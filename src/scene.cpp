#include "scene.hpp"

Scene::Scene(BridgeSceneManager* bsm){
	this->bsm = bsm;
}

void Scene::setBsm(BridgeSceneManager* bsm){
	this->bsm = bsm;
}

BridgeSceneManager* Scene::getBsm(){
	return this->bsm;
}