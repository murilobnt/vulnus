#include "game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle) :
gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
gameFrequency(sf::seconds(1.f / 60.f)),
scene(textureManager, nullptr),
sceneManager(textureManager, scene),
bsm(nullptr)
{
	bsm.setSceneManager(&sceneManager);
	scene.setBsm(&bsm);
	sceneManager.setScene(scene);
	
	this->gameWidth = gameWidth;
	this->gameHeight = gameHeight;
}

void Game::gameStart(){
	while(this->gameScreen.isOpen()){
		handleTimeActions();
		clearNDraw();

		this->clockHandler.restartClock();
		this->clockHandler.restartTimeHandler(&gameFrequency);
		sceneManager.resetTimeHandlers(clockHandler);
	}
}

void Game::processEvents(){
	sf::Event event;

	while (this->gameScreen.pollEvent(event))
	{
		if(event.type == sf::Event::Closed){
			gameScreen.close();
		}
		
		sceneManager.handleEvent(event, gameScreen);
	}
}

void Game::clearNDraw(){
	this->gameScreen.clear();

	sceneManager.drawEntities(gameScreen);

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
		sceneManager.doOperations();
		if(sceneManager.getScene().hasCamera)
			sceneManager.controlCamera(gameScreen);
	}

	sceneManager.doInternalTimedActions();
}