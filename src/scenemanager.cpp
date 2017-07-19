#include "structures/scenemanager.hpp"

SceneManager::SceneManager(TextureManager& textureManager) {
	this->scene = new MenuScene(textureManager, this);
	this->textureManager = textureManager;
}

SceneManager::~SceneManager(){
	delete scene;
}

void SceneManager::setScene(Scene* scene){
	this->scene = scene;
	scene->start();
}

void SceneManager::changeScene(SceneCatalog sceneCatalog){
	delete scene;
	switch (sceneCatalog){
		case GAME:
			this->scene = new GameScene(textureManager, this);
			this->scene->start();
		break;
		case MENU:
			this->scene = new MenuScene(textureManager, this);
			this->scene->start();
		break;
	}
}

void SceneManager::changeToRuntimeScene(SceneCatalog sceneCatalog){
	this->lastScene = this->scene;

	switch (sceneCatalog){
		case GAMEMENU:
			this->scene = new GameMenuScene(textureManager, this);
			this->scene->start();
		break;
	}
}

void SceneManager::setLastScene(){
	this->scene = lastScene;
}

Scene* SceneManager::getScene() const{
	return this->scene;
}

void SceneManager::start(){
	scene->start();
}

void SceneManager::handleEvent(sf::Event event, sf::RenderWindow& screen){
	scene->handleEvent(event, screen);
}

void SceneManager::controlCamera(sf::RenderWindow& window){
	scene->controlCamera(window);
}

void SceneManager::doOperations(){
	scene->doOperations();
}

void SceneManager::drawEntities(sf::RenderWindow& window){
	scene->drawEntities(window);
}

void SceneManager::doInternalTimedActions(){
	scene->doInternalTimedActions();
}

void SceneManager::resetTimeHandlers(ClockHandler& clockHandler){
	scene->resetTimeHandlers(clockHandler);
}