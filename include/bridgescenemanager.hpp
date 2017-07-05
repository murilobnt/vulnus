#ifndef _BRIDGESCENEMANAGER_HPP_
#define _BRIDGESCENEMANAGER_HPP_

#include "sscenemanager.hpp"

class BridgeSceneManager {
private:
	SSceneManager* sceneManager;

public:
	BridgeSceneManager(SSceneManager* sceneManager);	
	SSceneManager* getSceneManager() const;
	void setSceneManager(SSceneManager* sceneManager);
};

#endif