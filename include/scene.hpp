#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

#include "clockhandler.hpp"

class Scene {
public:
	bool hasCamera;

	virtual void start() = 0;
	virtual void handleEvent(sf::Event event, sf::RenderWindow& screen) = 0;
	virtual void doOperations() = 0;
	virtual void controlCamera(sf::RenderWindow& screen) = 0;
	virtual void drawEntities(sf::RenderWindow& window) = 0;
	virtual void doInternalTimedActions() = 0;
	virtual void resetTimeHandlers(ClockHandler& clockHandler) = 0;
};

#endif