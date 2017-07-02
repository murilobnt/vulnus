#include "gamescene.hpp"

GameScene::GameScene(TextureManager& textureManager) :
cutscene(0, textureManager.getTexture(CUTSCN), true),
level(1, textureManager.getTexture(AET)),
player(100.f, 2, textureManager.getTexture(AET), 32, 0, 32, 32, 0.2, 0, 32, 0, 32),
eventhandler(&player, &cutscene),
playerHealth(sf::Vector2f(player.getHealth(), 20.f)),
theTiles(0, 0, 64)
{
	hasCamera = true;

	backgroundSprite.setTexture(textureManager.getTexture(BG));
	backgroundSprite.setPosition(sf::Vector2f(0,0));
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, (64 * 32) + ((64 * 32)*0.1), 20*32));

	this->player.setSpritePosition(0, 480 - 64);
	playerHealth.setFillColor( sf::Color::Red );

	changeLevel();

	this->dynaGrid = level.generateDynamicGrid();
	this->colHandler = CollisionHandler(dynaGrid);
	
	font.loadFromFile("fonts/Ubuntu-C.tff");

	player.init(font);
	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			(*it).init(font);
		}
	}	
}

void GameScene::start(){
	soundTable.playSound(1);
	theTiles = level.getTileMap().getTiles();
}

void GameScene::handleEvent(sf::Event event, sf::RenderWindow& screen){
	if(eventhandler.handleEvent(event))
		eventhandler.handleMouseEvent(event, screen);
}

void GameScene::controlCamera(sf::RenderWindow& window){
	gameSceneManager.setCameraToWindow(window);
}

void GameScene::doOperations(){
	updateLogic();
}

void GameScene::drawEntities(sf::RenderWindow& window){
	window.draw(backgroundSprite);
	window.draw(level.getTileMap());
	this->level.drawEnemies(window);
	
	if(this->player.getInvulnerability()){
		while(player.getTimeHandler(3).timeToUpdate()){
			window.draw(player.getSprite());
		}
	} else {
		window.draw(player.getSprite());
	}

	if(this->player.getOnCombo()){
		this->player.drawText(window);
	}

	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			if((*it).getOnCombo()){
				(*it).drawText(window);
			}
		}
	}

	player.getPlayerWeapon().draw(window);

	if(this->cutscene.isActive()){
		this->cutscene.drawCutsceneBackground(window);
		this->cutscene.drawText(window);
	}

	window.draw(this->playerHealth);
}

void GameScene::doInternalTimedActions(){
	while(player.getTimeHandler(0).timeToUpdate()){
		this->player.applyPlayerAnimation();
		if (!currentEnemies->empty()){
			for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
				(&(*it))->applyEnemyAnimation();
			}
		}
	}

	if(player.getTimeHandler(2).timeToUpdate()){
		this->player.setInvulnerability(false);
	}

	if(player.getEntityComboDelimeter()->timeToUpdate()){
		this->player.cccomboBreak();
	}

	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			if((*it).getEntityComboDelimeter()->timeToUpdate()){
				(*it).cccomboBreak();
			}
		}
	}

	while(player.getTimeHandler(1).timeToUpdate() && player.moving && !player.getIsJumping()){
		soundTable.playSound(2);
	}
}

void GameScene::resetTimeHandlers(ClockHandler& clockHandler){
	clockHandler.restartTimeHandler(&player.getTimeHandler(0));
	clockHandler.restartTimeHandler(&player.getTimeHandler(1));

	if(this->player.getInvulnerability()){
		clockHandler.restartTimeHandler(&player.getTimeHandler(2));
		clockHandler.restartTimeHandler(&player.getTimeHandler(3));
	}

	if(this->player.getOnCombo()){
		clockHandler.restartTimeHandler(this->player.getEntityComboDelimeter());
	}

	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			clockHandler.restartTimeHandler((*it).getEntityComboDelimeter());
		}
	}
}

void GameScene::updateLogic(){
	launchCutscene();
	checkEnemyHealth();

	moveNStopPlayer();
	applyGravityOnEntities();
	
	refreshBackgroundPos();
	
	this->player.updateDamageText();

	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			(*it).updateDamageText();
		}
	}

	moveBullets();
	gameSceneManager.setCameraToPlayer(player, level.getTileMap().getLevelSize());
	restrictPlayerMovement();
	updatePlayerHealth();
}

void GameScene::launchCutscene(){
	if(this->cutscene.isActive()){
		this->cutscene.setTextToCamera(gameSceneManager.getCamera().getView());
	}
}

void GameScene::applyPlayerAnimation(){
	this->player.applyPlayerAnimation();
}

void GameScene::moveNStopPlayer(){
	player.movePlayer();
	theTiles.verifyEntityCollision(&player);
	player.getPlayerWeapon().isCollidingWithEnvironment(theTiles.getTileGrid());
	player.moveEntity(dynaGrid);

	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			(*it).moveEnemy(player.getSpritePosition());
			theTiles.verifyEntityCollision(&(*(it)));
			(*it).moveEntity(dynaGrid);

			if(colHandler.collisionBetweenPAndE(player, (*it))){
				player.receiveDamage((*it).getDamage());
				soundTable.playSound(3);	
			}

			if(player.getPlayerWeapon().isCollidingWithEnemy((*it))){
				(*it).receiveDamage(player.getPlayerWeapon().getDamage());
			}
		}
	}
}

void GameScene::restrictPlayerMovement(){
	player.desacceleratePlayer();
}

void GameScene::moveBullets(){
	player.getPlayerWeapon().update();
}

void GameScene::changeLevel(){
	this->currentEnemies = level.getEnemies();
}

void GameScene::refreshBackgroundPos(){
	gameSceneManager.setSpritePositionRelativeToCamera(backgroundSprite, -0.1 * gameSceneManager.getCameraPointRelativeToCenterX(), 0);
}

void GameScene::applyGravityOnEntities(){
	player.applyGravity();
	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			(*it).applyGravity();
		}
	}
}

void GameScene::updatePlayerHealth(){
	playerHealth.setSize(sf::Vector2f(player.getHealth(), 20.f));
	gameSceneManager.setSpritePositionRelativeToCamera(playerHealth, gameSceneManager.getCameraPointRelativeToCenterX() - (gameSceneManager.getCameraSize().x / 2), gameSceneManager.getCameraPointRelativeToCenterY() - (gameSceneManager.getCameraSize().y / 2));
}

void GameScene::checkEnemyHealth(){
	if (!currentEnemies->empty()){
		for(uint i = 0; i < currentEnemies->size(); i++){
			if((*currentEnemies)[i].getHealth() <= 0){
				currentEnemies->erase(this->currentEnemies->begin() +i);
			}
		}
	}
}