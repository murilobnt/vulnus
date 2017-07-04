#include "scenemanager.hpp"

SceneManager::SceneManager(){
}

void SceneManager::setScene(Scene& scene){
	this->scene = &scene;
	scene.start();
}

Scene& SceneManager::getScene() const{
	return *this->scene;
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