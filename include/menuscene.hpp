#ifndef _MENUSCENE_HPP_
#define _MENUSCENE_HPP_

#include "scene.hpp"
#include "texturemanager.hpp"
#include "clockhandler.hpp"
#include "menubutton.hpp"
#include "player.hpp"

class MenuScene : public Scene {
private:
	sf::Font font;

	Player player;

	MenuButton startGame;
	MenuButton loadGame;
	MenuButton exit;

	sf::Sprite background;

	MenuButton* buttonArray[3];

	int selected;

public:
	MenuScene(TextureManager& TextureManager, SSceneManager* sceneManager);

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