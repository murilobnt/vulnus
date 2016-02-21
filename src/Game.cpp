#include "Game.h"

// sf::Text text;
// sf::Font font;


Game::Game(int gameWidth, int gameHeight, std::string gameTitle) :
					 gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
					 camera(0.f, 0.f, 320.f, 240.f, 2.0),
					 aliveTexture("images/textures.png", 224, 128),
					 backgroundTexture("images/background.png", 1024, 960),
					 cutsceneTexture("images/rcutscene.png", 416, 96),
					 cutscene(0, *cutsceneTexture.getTexture()),
					 player(100.f, 2, *aliveTexture.getTexture(), 32, 0, 32, 32, 0.2)
{
	backgroundSprite.setTexture(*backgroundTexture.getTexture());
	backgroundSprite.setPosition(sf::Vector2f(0,0));
	this->gameWidth = gameWidth;
	this->gameHeight = gameHeight;
	//this->cutscene.setActive(0, true);
	this->gameScreen.setFramerateLimit(60);
	this->timeSinceLastUpdate = sf::Time::Zero;
	this->player.setSpritePosition(0, 960 - 64);
}

void Game::gameStart(){
	controlCamera();

	const int level[] =
	{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 2, 2, 2, 2, 3, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 3, 3, 2, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	const int selected[] = {1, 2};

	tileMap.load("images/tiles.png", sf::Vector2u(32, 32), level, 32, 30, selected, 2);

	theTiles = tileMap.getTiles();

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
				/*
				case sf::Event::KeyPressed :
				if(!this->cutscene.isActive()){
					player.handlePlayerInput(event.key.code, false); break;
				} else {
					cutscene.proceedCutscene(event.key.code, true);
				}
				break;

				case sf::Event::KeyReleased :
					if(this->cutscene.isActive()){
						cutscene.proceedCutscene(event.key.code, false);
					} else {
						player.handlePlayerInput(event.key.code, true);
					}
				break;
				*/
	            switch(event.type){
								case sf::Event::KeyPressed :
								if(!this->cutscene.isActive()){
									player.handlePlayerInput(event.key.code, false); //break;
								} else {
									cutscene.proceedCutscene(event.key.code, true);
								}
								break;

								case sf::Event::KeyReleased :
									if(this->cutscene.isActive()){
										cutscene.proceedCutscene(event.key.code, false);
									} else {
										player.handlePlayerInput(event.key.code, true);
									}
								break;
									//case sf::Event::KeyReleased : player.handlePlayerInput(event.key.code, true); break;
									case sf::Event::MouseButtonPressed :
									if(!this->cutscene.isActive()){
										player.handleMouseInput(this->gameScreen.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)));
										//player.handlePlayerInput(event.key.code, false); break;
									}
										break;
	                case sf::Event::Closed : this->gameScreen.close(); break;
	            }
	    }
			moveNStopPlayer();
			applyPlayerAnimation(&player);
			moveBullets();
			controlCamera();
			restrictPlayerMovement();
	    clearNDraw();
}

void Game::launchCutscene(){
	if(this->cutscene.isActive()){
		this->cutscene.setTextToCamera(this->camera.getObject());
	}
}

void Game::applyPlayerAnimation(Player* player){
	player->applyPlayerAnimation(&this->timeSinceLastUpdate);
}

void Game::moveNStopPlayer(){
	player.movePlayer();
	theTiles.verifyPlayerCollision(&player);
	//std::vector<Bullet>* bullets = player.getTheBulletsObject();
	theTiles.verifyBulletCollision(player.getTheBulletsObject());
	player.moveEntity();
}

void Game::controlCamera(){
	this->camera.getToPlayer(player, tileMap.getLevelSize());
	this->gameScreen.setView(camera.getObject());
}

void Game::restrictPlayerMovement(){
	player.desacceleratePlayer();
	player.checkHalfOne();
}

void Game::clearNDraw(){
	this->gameScreen.clear();
	this->gameScreen.draw(backgroundSprite);
	this->gameScreen.draw(tileMap);
	this->gameScreen.draw(player.getSprite());
	if(this->cutscene.isActive()){
		this->cutscene.drawCutsceneBackground(this->gameScreen);
		this->cutscene.drawText(this->gameScreen);
	}
	drawBullets();
	this->gameScreen.display();
}

void Game::drawBullets(){
	std::vector<Bullet> theBullets = player.getTheBullets();
	if(theBullets.empty()){
		return;
	}

	for(std::vector<Bullet>::iterator it = theBullets.begin(); it != theBullets.end(); ++it){
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
