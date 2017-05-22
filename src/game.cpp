#include "game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle) :
gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
gameCamera(0.f, 0.f, 320.f, 240.f, 2.0),
aliveTexture("images/aliveentities.png", 128, 64),
backgroundTexture("images/background3.png", 100, 100, true),
cutsceneTexture("images/rcutscene.png", 416, 96),
cutscene(0, *cutsceneTexture.getTexture(), true),
level(1, *aliveTexture.getTexture()),
player(100.f, 2, *aliveTexture.getTexture(), 32, 0, 32, 32, 0.2, 0, 32, 0, 32),
eventhandler(&player, &cutscene),
playerHealth(sf::Vector2f(player.getHealth(), 20.f)),
theTiles(0, 0, 64)
{
	bgm.openFromFile("sounds/Overworld.ogg");
	bgm.setLoop(true);

	backgroundSprite.setTexture(*backgroundTexture.getTexture());
	backgroundSprite.setPosition(sf::Vector2f(0,0));
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1400, 1000));

	this->gameWidth = gameWidth;
	this->gameHeight = gameHeight;

	this->ups = sf::seconds(1.f / 60.f);
	this->timeSinceLastUpdate = sf::Time::Zero;
	this->fpsTime = sf::Time::Zero;
	this->player.setSpritePosition(0, 480 - 64);

	playerHealth.setFillColor( sf::Color::Red );

	changeLevel();
}

void Game::gameStart(){
	bgm.play();
	controlCamera();

	theTiles = level.getTileMap().getTiles();

	while(this->gameScreen.isOpen()){
		processEvents();
		
		while(this->timeSinceLastUpdate > this->ups){
			this->timeSinceLastUpdate -= this->ups;
			updateLogic();
		}

		while(this->fpsTime > player.framerateUp){
			this->fpsTime -= player.framerateUp;
			applyPlayerAnimation();
			for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
				(&(*it))->applyEnemyAnimation();
			}
		}

		clearNDraw();
		
		this->elapsedTime = this->clock.restart();
		this->timeSinceLastUpdate += elapsedTime;
		this->fpsTime += elapsedTime;
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
	
	moveNStopPlayer();
	applyGravityOnEntities();

	refreshBackgroundPos();
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
	//theTiles.verifyBulletCollision(player.getTheBulletsObject());
	player.moveEntity();

	for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
		(*it).moveEnemy(player.getSprite().getPosition());
		theTiles.verifyEntityCollision(&(*(it)));
		(*it).moveEntity();
		if((*it).getSprite().getGlobalBounds().intersects(player.getSprite().getGlobalBounds())){
			player.receiveDamage(1);
		}
	}
}

void Game::controlCamera(){
	this->gameCamera.getToPlayer(player, level.getTileMap().getLevelSize());
	this->gameScreen.setView(gameCamera.getObject());
}

void Game::restrictPlayerMovement(){
	player.desacceleratePlayer();
	//player.checkHalfOne();
}

void Game::clearNDraw(){
	this->gameScreen.clear();

	this->gameScreen.draw(backgroundSprite);
	this->gameScreen.draw(level.getTileMap());
	this->level.drawEnemies(this->gameScreen);
	this->gameScreen.draw(player.getSprite());

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
	for(std::vector<Enemy>::iterator it = currentEnemies->begin(); it != currentEnemies->end(); ++it){
		(*it).applyGravity();
	}
}

void Game::updatePlayerHealth(){
	sf::Vector2f camPos = this->gameCamera.getObject().getCenter();
	sf::Vector2f camSize = this->gameCamera.getObject().getSize();

	//playerHealth = sf::RectangleShape(sf::Vector2f(player.getHealth(), 20.f));
	playerHealth.setSize(sf::Vector2f(player.getHealth(), 20.f));
	playerHealth.setPosition(sf::Vector2f(camPos.x - (camSize.x / 2), camPos.y - (camSize.y / 2)));
}