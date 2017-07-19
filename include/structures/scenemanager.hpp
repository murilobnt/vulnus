#ifndef _SCENEMANAGER_HPP_
#define _SCENEMANAGER_HPP_

#include <cstring>

#include "generics/scene.hpp"
#include "structures/texturemanager.hpp"
#include "scenes/gamescene.hpp"
#include "scenes/menuscene.hpp"
#include "scenes/gamemenuscene.hpp"
#include "enums/scenecatalog.hpp"

class SceneManager : public SSceneManager {
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