#include "game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle) :
gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
gameCamera(0.f, 0.f, 320.f, 240.f, 2.0),
aliveTexture("images/aliveentitiesa.png", 128, 64),
backgroundTexture("images/background4.png", 100, 100, true),
cutsceneTexture("images/rcutscene.png", 416, 96),
cutscene(0, *cutsceneTexture.getTexture(), true),
level(1, *aliveTexture.getTexture()),
player(100.f, 2, *aliveTexture.getTexture(), 32, 0, 32, 32, 0.2, 0, 32, 0, 32),
theTiles(0, 0, 64)
{
	bgm.openFromFile("sounds/Overworld.ogg");
	bgm.setLoop(true);

	backgroundSprite.setTexture(*backgroundTexture.getTexture());
	backgroundSprite.setPosition(sf::Vector2f(0,0));
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1400, 1000));

	this->gameWidth = gameWidth;
	this->gameHeight = gameHeight;
	this->gameScreen.setFramerateLimit(60);
	this->timeSinceLastUpdate = sf::Time::Zero;
	this->player.setSpritePosition(0, 480 - 64);
}

void Game::gameStart(){
	bgm.play();
	controlCamera();

	theTiles = level.getTileMap().getTiles();

	while(this->gameScreen.isOpen()){
		this->elapsedTime = this->clock.restart();
		this->timeSinceLastUpdate += elapsedTime;
		gameLoop();
	}
}

void Game::gameLoop(){
	sf::Event event;

	player.applyGravity();
	launchCutscene();

	while (this->gameScreen.pollEvent(event))
	{
	    // Next step: Create an event handler (hint: Use event as a parameter).
		switch(event.type){
			case sf::Event::KeyPressed :
			if(!this->cutscene.isActive()){
				this->inputHandler.handlePlayerInput(&player, event.key.code, false);
			} else {
				cutscene.proceedCutscene(event.key.code, true);
			}
			break;

			case sf::Event::KeyReleased :
			if(this->cutscene.isActive()){
				cutscene.proceedCutscene(event.key.code, false);
			} else {
				this->inputHandler.handlePlayerInput(&player, event.key.code, true);
			}
			break;
			case sf::Event::MouseButtonPressed :
			if(!this->cutscene.isActive()){
				this->inputHandler.handleMouseInput(&player, this->gameScreen.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)));
			}
			break;
			case sf::Event::Closed : this->gameScreen.close(); break;
		}
	}

	moveNStopPlayer();
	applyPlayerAnimation(&player);
	refreshBackgroundPos();
	moveBullets();
	controlCamera();
	restrictPlayerMovement();
	clearNDraw();
}

void Game::launchCutscene(){
	if(this->cutscene.isActive()){
		this->cutscene.setTextToCamera(this->gameCamera.getObject());
	}
}

void Game::applyPlayerAnimation(Player* player){
	player->applyPlayerAnimation(&this->timeSinceLastUpdate);
}

void Game::moveNStopPlayer(){
	player.movePlayer();
	theTiles.verifyPlayerCollision(&player);
	theTiles.verifyBulletCollision(player.getTheBulletsObject());
	player.moveEntity();
}

void Game::controlCamera(){
	this->gameCamera.getToPlayer(player, level.getTileMap().getLevelSize());
	this->gameScreen.setView(gameCamera.getObject());
}

void Game::restrictPlayerMovement(){
	player.desacceleratePlayer();
	player.checkHalfOne();
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
