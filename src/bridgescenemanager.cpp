#include "bridgescenemanager.hpp"

BridgeSceneManager::BridgeSceneManager(SSceneManager* sceneManager) {
	this->sceneManager = sceneManager;
}

SSceneManager* BridgeSceneManager::getSceneManager() const{
	return this->sceneManager;
}

void BridgeSceneManager::setSceneManager(SSceneManager* sceneManager){
	this->sceneManager = sceneManager;
}