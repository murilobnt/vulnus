#include "game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle) :
gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
gameFrequency(sf::seconds(1.f / 60.f)),
scene(textureManager)
{
	this->gameWidth = gameWidth;
	this->gameHeight = gameHeight;
	sceneManager.setScene(scene);
	sceneManager.getScene().start();
}

void Game::gameStart(){
	while(this->gameScreen.isOpen()){
		handleTimeActions();
		clearNDraw();

		this->clockHandler.restartClock();
		this->clockHandler.restartTimeHandler(&gameFrequency);
		sceneManager.getScene().resetTimeHandlers(clockHandler);
	}
}

void Game::processEvents(){
	sf::Event event;

	while (this->gameScreen.pollEvent(event))
	{
		if(event.type == sf::Event::Closed){
			gameScreen.close();
		}
		
		sceneManager.getScene().handleEvent(event, gameScreen);
	}
}

void Game::clearNDraw(){
	this->gameScreen.clear();

	sceneManager.getScene().drawEntities(gameScreen);

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
		sceneManager.getScene().doOperations();
		if(sceneManager.getScene().hasCamera)
			sceneManager.getScene().controlCamera(gameScreen);
	}

	sceneManager.getScene().doInternalTimedActions();
}