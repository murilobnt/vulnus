#ifndef _SCENEMANAGER_HPP_
#define _SCENEMANAGER_HPP_

#include "scene.hpp"

class SceneManager {
private:
	Scene* scene;

public:
	SceneManager();
	void setScene(Scene& scene);
	Scene& getScene() const;

	void start();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void controlCamera(sf::RenderWindow& window);
	void doOperations();
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);
};

#endif