#ifndef _MENUSCENE_HPP_
#define _MENUSCENE_HPP_

#include "scene.hpp"
#include "texturemanager.hpp"
#include "clockhandler.hpp"

class MenuScene : public Scene {
public:
	MenuScene(TextureManager& textureManager);

	void start();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void controlCamera(sf::RenderWindow& window);
	void doOperations();	
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);
};

#endif