#ifndef _GAMEMENUSCENE_HPP_
#define _GAMEMENUSCENE_HPP_

#include "scene.hpp"
#include "scenemanager.hpp"
#include "menubutton.hpp"
#include "texturemanager.hpp"

class GameMenuScene : public Scene {
private:
	sf::Font font;

	MenuButton resume;
	MenuButton exit;

	sf::Sprite background;

	MenuButton* buttonArray[2];

	int selected;
public:
	GameMenuScene(TextureManager& TextureManager, SSceneManager* sceneManager);

	void start();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void controlCamera(sf::RenderWindow& window);
	void doOperations();
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);
	void changeScene(SceneCatalog sceneCatalog);
};

#endif