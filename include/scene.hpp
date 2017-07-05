#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

#include "clockhandler.hpp"
#include "sscenemanager.hpp"
#include "scenecatalog.hpp"

class Scene {
protected:
	SSceneManager* sceneManager;
	
public:
	bool hasCamera;

	Scene(SSceneManager* sceneManager);

	virtual void start() = 0;
	virtual void handleEvent(sf::Event event, sf::RenderWindow& screen) = 0;
	virtual void controlCamera(sf::RenderWindow& window) = 0;
	virtual void doOperations() = 0;
	virtual void drawEntities(sf::RenderWindow& window) = 0;
	virtual void doInternalTimedActions() = 0;
	virtual void resetTimeHandlers(ClockHandler& clockHandler) = 0;
	virtual void changeScene(SceneCatalog sceneCatalog) = 0;
	void setSSceneManager(SSceneManager* sceneManager);
	SSceneManager* getSSceneManager();
};

#endif