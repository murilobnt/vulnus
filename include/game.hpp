#ifndef _GAME_HPP_
#define _GAME_HPP_

// # External
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>

// # Internal
#include "textureindex.hpp"

#include "texturemanager.hpp"
#include "clockhandler.hpp"
#include "generictimehandler.hpp"
#include "dynamicgrid.hpp"
#include "soundtable.hpp"
#include "collisionhandler.hpp"
#include "timehandlers.hpp"
#include "gamescene.hpp"
#include "scenemanager.hpp"

class Game{

private:
	sf::RenderWindow gameScreen;

	int gameWidth;
	int gameHeight;

	ClockHandler clockHandler;
	TextureManager textureManager;
	GenericTimeHandler gameFrequency;

	GameScene scene;
	SceneManager sceneManager;

public:
	/**
	 * Constructor.
	 * @param gameWidth the width of the window
	 * @param gameHeight the height of the window
	 * @param gameTitle the title of the window
	 */
	Game(int gameWidth, int gameHeight, std::string gameTitle);
	
	void gameStart();
	void processEvents();
	void clearNDraw();
	int getGameWidth();
	int getGameHeight();

	void handleTimeActions();
};

#endif
