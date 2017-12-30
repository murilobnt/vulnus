#include "generics/scene.hpp"

Scene::Scene(SceneManager* sceneManager){
	this->sceneManager = sceneManager;
}

void Scene::setSceneManager(SceneManager* sceneManager){
	this->sceneManager = sceneManager;
}

SceneManager* Scene::getSceneManager(){
	return this->sceneManager;
}