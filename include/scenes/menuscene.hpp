#ifndef _MENUSCENE_HPP_
#define _MENUSCENE_HPP_

#include "generics/scene.hpp"
#include "structures/texturemanager.hpp"
#include "entities/clock/clockhandler.hpp"
#include "scenes/uicomponents/menubutton.hpp"
#include "entities/gamecomponents/player.hpp"

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
	MenuScene(TextureManager& TextureManager, SceneManager* sceneManager);

	void start();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void controlCamera(sf::RenderWindow& window);
	void doOperations();	
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);
	void changeScene(SceneCatalog sceneCatalog);
	void onExit();
	void resumeScene();
};

#endif