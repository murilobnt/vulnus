#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

#include "structures/scenemanager.hpp"
#include "entities/clock/clockhandler.hpp"
#include "enums/scenecatalog.hpp"

class Scene {
protected:
	SceneManager* sceneManager;
	
public:
	bool hasCamera;

	Scene(SceneManager* sceneManager);

	virtual void start() = 0;
	virtual void handleEvent(sf::Event event, sf::RenderWindow& screen) = 0;
	virtual void controlCamera(sf::RenderWindow& window) = 0;
	virtual void doOperations() = 0;
	virtual void drawEntities(sf::RenderWindow& window) = 0;
	virtual void doInternalTimedActions() = 0;
	virtual void resetTimeHandlers(ClockHandler& clockHandler) = 0;
	virtual void changeScene(SceneCatalog sceneCatalog) = 0;
	void setSceneManager(SceneManager* sceneManager);
	SceneManager* getSceneManager();

	virtual void onExit() = 0;
	virtual void resumeScene() = 0;
};

#endif