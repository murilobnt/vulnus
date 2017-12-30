#ifndef _SCENEMANAGER_HPP_
#define _SCENEMANAGER_HPP_

#include <cstring>

#include "structures/texturemanager.hpp"
#include "entities/clock/clockhandler.hpp"
#include "enums/scenecatalog.hpp"

class Scene;
class GameScene;
class MenuScene;
class GameMenuScene;

class SceneManager {
private:
	Scene* scene;
	Scene* lastScene;

	TextureManager textureManager;

public:
	SceneManager(TextureManager& textureManager);
	~SceneManager();
	
	void setScene(Scene* scene);
	void changeScene(SceneCatalog sceneCatalog);
	void changeToRuntimeScene(SceneCatalog sceneCatalog);
	void removeLastScene();
	void setLastScene();
	Scene* getScene() const;

	void start();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void controlCamera(sf::RenderWindow& window);
	void doOperations();
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);
};

#endif