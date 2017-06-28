#include "game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle) :
gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
gameCamera(0.f, 0.f, 320.f, 240.f, 2.0),
cutscene(0, textureManager.getTexture(CUTSCN), true),
level(1, textureManager.getTexture(AET)),
player(100.f, 2, textureManager.getTexture(AET), 32, 0, 32, 32, 0.2, 0, 32, 0, 32),
eventhandler(&player, &cutscene),
playerHealth(sf::Vector2f(player.getHealth(), 20.f)),
theTiles(0, 0, 64),
gameFrequency(sf::seconds(1.f / 60.f))
{
	backgroundSprite.setTexture(textureManager.getTexture(BG));
	backgroundSprite.setPosition(sf::Vector2f(0,0));

	backgroundSprite.setTextureRect(sf::IntRect(0, 0, (64 * 32) + ((64 * 32)*0.1), 20*32));

	this->gameWidth = gameWidth;
	this->gameHeight = gameHeight;

	this->player.setSpritePosition(0, 480 - 64);

	playerHealth.setFillColor( sf::Color::Red );

	changeLevel();
	this->dynaGrid = level.generateDynamicGrid();
	this->colHandler = CollisionHandler(dynaGrid);

	this->font.loadFromFile("fonts/Ubuntu-C.tff");

	player.init(font);
	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			(*it).init(font);
		}
	}
}

void Game::gameStart(){
	soundTable.playSound(1);
	controlCamera();

	theTiles = level.getTileMap().getTiles();

	while(this->gameScreen.isOpen()){
		processEvents();
		handleTimeActions();
		clearNDraw();

		this->clockHandler.restartClock();

		this->clockHandler.restartTimeHandler(&gameFrequency);
		this->clockHandler.restartTimeHandler(&player.getTimeHandler(0));
		this->clockHandler.restartTimeHandler(&player.getTimeHandler(1));

		if(this->player.getInvulnerability()){
			this->clockHandler.restartTimeHandler(&player.getTimeHandler(2));
			this->clockHandler.restartTimeHandler(&player.getTimeHandler(3));
		}

		if(this->player.getOnCombo()){
			this->clockHandler.restartTimeHandler(this->player.getEntityComboDelimeter());
		}

		if (!currentEnemies->empty()){
			for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
				this->clockHandler.restartTimeHandler((*it).getEntityComboDelimeter());
			}
		}
	}
}

void Game::processEvents(){
	sf::Event event;

	while (this->gameScreen.pollEvent(event))
	{
		if(this->eventhandler.handleEvent(event))
			this->eventhandler.handleScreenEvent(event, &this->gameScreen);
	}
}

void Game::updateLogic(){
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
	controlCamera();
	restrictPlayerMovement();
	updatePlayerHealth();
}

void Game::launchCutscene(){
	if(this->cutscene.isActive()){
		this->cutscene.setTextToCamera(this->gameCamera.getView());
	}
}

void Game::applyPlayerAnimation(){
	this->player.applyPlayerAnimation();
}

void Game::moveNStopPlayer(){
	player.movePlayer();
	theTiles.verifyEntityCollision(&player);
	player.getPlayerWeapon().isCollidingWithEnvironment(theTiles.getTileGrid());
	player.moveEntity(dynaGrid);

	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			(*it).moveEnemy(player.getSprite().getPosition());
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

void Game::controlCamera(){
	this->gameCamera.getToPlayer(player, level.getTileMap().getLevelSize());
	this->gameScreen.setView(gameCamera.getView());
}

void Game::restrictPlayerMovement(){
	player.desacceleratePlayer();
}

void Game::clearNDraw(){
	this->gameScreen.clear();

	this->gameScreen.draw(backgroundSprite);
	this->gameScreen.draw(level.getTileMap());
	this->level.drawEnemies(this->gameScreen);
	
	if(this->player.getInvulnerability()){
		while(player.getTimeHandler(3).timeToUpdate()){
			this->gameScreen.draw(player.getSprite());
		}
	} else {
		this->gameScreen.draw(player.getSprite());
	}

	if(this->player.getOnCombo()){
		this->player.drawText(this->gameScreen);
	}

	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			if((*it).getOnCombo()){
				(*it).drawText(this->gameScreen);
			}
		}
	}

	drawBullets();

	if(this->cutscene.isActive()){
		this->cutscene.drawCutsceneBackground(this->gameScreen);
		this->cutscene.drawText(this->gameScreen);
	}

	this->gameScreen.draw(this->playerHealth);

	this->gameScreen.display();
}

void Game::drawBullets(){
	player.getPlayerWeapon().draw(this->gameScreen);
}

void Game::moveBullets(){
	player.getPlayerWeapon().update();
}

int Game::getGameWidth(){
	return this->gameWidth;
}

int Game::getGameHeight(){
	return this->gameHeight;
}

void Game::refreshBackgroundPos(){
	this->backgroundSprite.setPosition(sf::Vector2f(-0.1 * this->gameCamera.getView().getCenter().x, 0));
}

void Game::changeLevel(){
	this->currentEnemies = level.getEnemies();
}

void Game::applyGravityOnEntities(){
	player.applyGravity();
	if (!currentEnemies->empty()){
		for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
			(*it).applyGravity();
		}
	}
}

void Game::updatePlayerHealth(){
	sf::Vector2f camPos = this->gameCamera.getView().getCenter();
	sf::Vector2f camSize = this->gameCamera.getView().getSize();

	playerHealth.setSize(sf::Vector2f(player.getHealth(), 20.f));
	playerHealth.setPosition(sf::Vector2f(camPos.x - (camSize.x / 2), camPos.y - (camSize.y / 2)));
}

void Game::handleTimeActions(){
	while(gameFrequency.timeToUpdate()){
		updateLogic();
	}

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

void Game::checkEnemyHealth(){
	if (!currentEnemies->empty()){
		for(uint i = 0; i < currentEnemies->size(); i++){
			if((*currentEnemies)[i].getHealth() <= 0){
				currentEnemies->erase(this->currentEnemies->begin() +i);
			}
		}
	}
}