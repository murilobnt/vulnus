#include "scenes/gamescene.hpp"

GameScene::GameScene(TextureManager& textureManager, SSceneManager* sceneManager) :
Scene::Scene(sceneManager),
cutscene(0, textureManager.getTexture(CUTSCN), 0, 0, 416, 96, true),
player(100.f, 2, textureManager.getTexture(AET), 32, 0, 32, 32, 0.2, 0, 32, 0, 32),
playerHealth(sf::Vector2f(player.getHealth(), 20.f)),
theTiles(0, 0, 64),
layer1(textureManager.getTexture(BG), 0.1),
layer2(textureManager.getTexture(SKY), 0.3),
gameTime(&backgroundSprite, true)
{
	this->filterTH = gameTime.getFilterCC().getTimeHandler();
	this->bgTH = gameTime.getBgCC().getTimeHandler();

	level.loadLevel(player, 1, textureManager.getTexture(AET));

	hasCamera = true;

	layer1.initLevelWandH(level.getW(), level.getH());
	layer2.initLevelWandH(level.getW(), 136);

	backgroundSprite = layer1.getSprite();
	skySprite = layer2.getSprite();

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
	switch(event.type){
		case sf::Event::KeyReleased :
			switch(event.key.code){
				case sf::Keyboard::Escape:
					this->gameSceneManager.resetCameraPosition();
					this->gameSceneManager.setCameraToWindow(screen);
					this->soundTable.pauseSound();
					getSSceneManager()->changeToRuntimeScene(GAMEMENU);
				break;
			}
	}
	
	eventhandler.handleEvent(event, cutscene);
	
	if(!this->cutscene.isActive()){
		eventhandler.handleEvent(event, player);
		eventhandler.handleEvent(event, gameTime);
	
		pmc.controlEntityByMouse(event, player, screen.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)));
	}
}

void GameScene::controlCamera(sf::RenderWindow& window){
	gameSceneManager.setCameraToWindow(window);
}

void GameScene::doOperations(){
	updateLogic();
}

void GameScene::drawEntities(sf::RenderWindow& window){
	gameTime.clearRenderTexture();
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

	player.getPlayerWeapon().draw(window);
	window.draw(skySprite);
	window.draw(gameTime.getFilter());

	if(this->cutscene.isActive()){
		this->cutscene.drawCutsceneBackground(window);
		this->cutscene.drawText(window);
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
	
	window.draw(gameTime.getText());
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

	if(gameTime.getTimeHandler().timeToUpdate() && !cutscene.isActive()){
		gameTime.updateTime();
	}

	if(gameTime.getFilterCC().isInTransition() && filterTH.timeToUpdate()){
		gameTime.getFilterCC().updateTransition();
	}

	if(gameTime.getBgCC().isInTransition() && bgTH.timeToUpdate()){
		gameTime.getBgCC().updateTransition();
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

	if(!cutscene.isActive())
		clockHandler.restartTimeHandler(&gameTime.getTimeHandler());

	if(gameTime.getFilterCC().isInTransition())
		clockHandler.restartTimeHandler(&this->filterTH);

	if(gameTime.getBgCC().isInTransition())
		clockHandler.restartTimeHandler(&this->bgTH);	
}

void GameScene::changeScene(SceneCatalog sceneCatalog){
	getSSceneManager()->changeScene(sceneCatalog);
}

void GameScene::updateLogic(){
	launchCutscene();
	checkEnemyHealth();

	moveNStopPlayer();
	applyGravityOnEntities();
	
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
	refreshTimePos();
	refreshBackgroundPos();
}

void GameScene::onExit(){
	this->soundTable.stopSound();
}

void GameScene::resumeScene(){
	this->soundTable.playSound(1);
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
	backgroundSprite.setPosition(sf::Vector2f(-layer1.getMovementFactor() * gameSceneManager.getCameraPointRelativeToCenterX(), 0));
	skySprite.setPosition(sf::Vector2f(-layer2.getMovementFactor() * gameSceneManager.getCameraPointRelativeToCenterX(), 0));
	gameSceneManager.setSpritePositionRelativeToCamera(gameTime.getFilter(), -400, -300);
}

void GameScene::refreshTimePos(){
	gameSceneManager.setSpritePositionRelativeToCamera(gameTime.getText(), 400 - gameTime.getText().getLocalBounds().width, -300);
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
	gameSceneManager.setSpritePositionRelativeToCamera(playerHealth, -(gameSceneManager.getCameraSize().x / 2), -(gameSceneManager.getCameraSize().y / 2));
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