#include "game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle) :
gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
gameCamera(0.f, 0.f, 320.f, 240.f, 2.0),
aliveTexture("images/aliveentities.png", 128, 64, false, true),
backgroundTexture("images/background3.png", 100, 100, true),
cutsceneTexture("images/rcutscene.png", 416, 96),
cutscene(0, *cutsceneTexture.getTexture(), true),
level(1, *aliveTexture.getTexture()),
player(100.f, 2, *aliveTexture.getTexture(), 32, 0, 32, 32, 0.2, 0, 32, 0, 32),
eventhandler(&player, &cutscene),
playerHealth(sf::Vector2f(player.getHealth(), 20.f)),
theTiles(0, 0, 64)
{
	gameFrequency = this->clockHandler.getHandler(GAMEFREQ);
	playerAnimation = this->clockHandler.getHandler(PLAYERANIM);
	playerSound = this->clockHandler.getHandler(PLAYERSOUND);
	playerInvulnerability = this->clockHandler.getHandler(PLAYERINVULN);
	playerInvulnerabilityAnimation = this->clockHandler.getHandler(PLAYERINVULNANIM);

	backgroundSprite.setTexture(*backgroundTexture.getTexture());
	backgroundSprite.setPosition(sf::Vector2f(0,0));
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1400, 1000));

	this->gameWidth = gameWidth;
	this->gameHeight = gameHeight;

	this->player.setSpritePosition(0, 480 - 64);

	playerHealth.setFillColor( sf::Color::Red );

	changeLevel();
	this->dynaGrid = level.generateDynamicGrid();
	this->colHandler = CollisionHandler(dynaGrid);

	this->playerBulletsRef = this->player.getTheBulletsObject();
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
		this->clockHandler.restartTimeHandlers();

		if(this->player.getInvulnerability()){
			this->clockHandler.restartInvulnTimeHandlers();
		}

		if(this->player.getOnCombo()){
			this->clockHandler.restartComboTimeHandlers(this->player.getEntityComboDelimeter());
		}

		if (!currentEnemies->empty()){
			for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
				this->clockHandler.restartComboTimeHandlers((*it).getEntityComboDelimeter());
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
	moveBullets();
	controlCamera();
	restrictPlayerMovement();
	updatePlayerHealth();
}

void Game::launchCutscene(){
	if(this->cutscene.isActive()){
		this->cutscene.setTextToCamera(this->gameCamera.getObject());
	}
}

void Game::applyPlayerAnimation(){
	this->player.applyPlayerAnimation();
}

void Game::moveNStopPlayer(){
	player.movePlayer();
	theTiles.verifyEntityCollision(&player);
	theTiles.verifyBulletCollision(playerBulletsRef);
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

			for(std::vector<Bullet>::iterator bIt = playerBulletsRef->begin(); bIt != playerBulletsRef->end(); ++bIt){
				if(colHandler.collisionBetweenBAndE((*bIt), (*it))){
					(*it).receiveDamage(5);
					(*bIt).shouldBeDestroyed(true);
				}
			}
		}
	}
}

void Game::controlCamera(){
	this->gameCamera.getToPlayer(player, level.getTileMap().getLevelSize());
	this->gameScreen.setView(gameCamera.getObject());
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
		while(playerInvulnerabilityAnimation->timeToUpdate()){
			this->gameScreen.draw(player.getSprite());
		}
	} else {
		this->gameScreen.draw(player.getSprite());
	}

	if(this->player.getOnCombo()){
		//this->gameScreen.draw(this->player.getDamageOutput());
		this->player.drawText(this->gameScreen);
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
	std::vector<Bullet> playerBullets = player.getTheBullets();
	if(playerBullets.empty()){
		return;
	}

	for(std::vector<Bullet>::iterator it = playerBullets.begin(); it != playerBullets.end(); ++it){
		this->gameScreen.draw((*it).getBullet());
	}
}

void Game::moveBullets(){
	player.moveNDeleteBullets();
}

int Game::getGameWidth(){
	return this->gameWidth;
}

int Game::getGameHeight(){
	return this->gameHeight;
}

void Game::refreshBackgroundPos(){
	this->backgroundSprite.setPosition(sf::Vector2f(-0.1 * this->gameCamera.getObject().getCenter().x, 0));
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
	sf::Vector2f camPos = this->gameCamera.getObject().getCenter();
	sf::Vector2f camSize = this->gameCamera.getObject().getSize();

	playerHealth.setSize(sf::Vector2f(player.getHealth(), 20.f));
	playerHealth.setPosition(sf::Vector2f(camPos.x - (camSize.x / 2), camPos.y - (camSize.y / 2)));
}

void Game::handleTimeActions(){
	while(gameFrequency->timeToUpdate()){
		updateLogic();
	}

	while(playerAnimation->timeToUpdate()){
		this->player.applyPlayerAnimation();
		if (!currentEnemies->empty()){
			for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
				(&(*it))->applyEnemyAnimation();
			}
		}
	}

	if(playerInvulnerability->timeToUpdate()){
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

	while(playerSound->timeToUpdate() && player.moving && !player.getIsJumping()){
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