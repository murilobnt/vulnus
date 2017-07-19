#include "generics/scene.hpp"

Scene::Scene(SSceneManager* sceneManager){
	this->sceneManager = sceneManager;
}

void Scene::setSSceneManager(SSceneManager* sceneManager){
	this->sceneManager = sceneManager;
}

SSceneManager* Scene::getSSceneManager(){
	return this->sceneManager;
}