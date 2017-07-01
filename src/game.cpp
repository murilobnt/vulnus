#include "game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle) :
gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
gameFrequency(sf::seconds(1.f / 60.f)),
scene(textureManager)
{
	this->gameWidth = gameWidth;
	this->gameHeight = gameHeight;
	scene.start();
}

void Game::gameStart(){
	while(this->gameScreen.isOpen()){
		handleTimeActions();
		clearNDraw();

		this->clockHandler.restartClock();
		this->clockHandler.restartTimeHandler(&gameFrequency);
		scene.resetTimeHandlers(clockHandler);
	}
}

void Game::processEvents(){
	sf::Event event;

	while (this->gameScreen.pollEvent(event))
	{
		if(event.type == sf::Event::Closed){
			gameScreen.close();
		}
		
		scene.handleEvent(event, gameScreen);
	}
}

void Game::clearNDraw(){
	this->gameScreen.clear();

	scene.drawEntities(gameScreen);

	this->gameScreen.display();
}

int Game::getGameWidth(){
	return this->gameWidth;
}

int Game::getGameHeight(){
	return this->gameHeight;
}

void Game::handleTimeActions(){
	while(gameFrequency.timeToUpdate()){
		processEvents();
		if(scene.hasCamera)
			scene.controlCamera(gameScreen);
		scene.doOperations();
	}

	scene.doInternalTimedActions();
}