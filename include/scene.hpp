#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

#include "clockhandler.hpp"
#include "bridgescenemanager.hpp"

class Scene {
protected:
	BridgeSceneManager* bsm;
	
public:
	bool hasCamera;

	Scene(BridgeSceneManager* bsm);

	virtual void start() = 0;
	virtual void handleEvent(sf::Event event, sf::RenderWindow& screen) = 0;
	virtual void controlCamera(sf::RenderWindow& window) = 0;
	virtual void doOperations() = 0;
	virtual void drawEntities(sf::RenderWindow& window) = 0;
	virtual void doInternalTimedActions() = 0;
	virtual void resetTimeHandlers(ClockHandler& clockHandler) = 0;
	virtual void changeScene() = 0;
	void setBsm(BridgeSceneManager* bsm);
	BridgeSceneManager* getBsm();
};

#endif