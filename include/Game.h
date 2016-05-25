#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Camera.h"
#include "Player.h"
#include "TextureSet.h"
#include "Level.h"
#include "TileSet.h"
#include "Bullet.h"
#include "Cutscene.h"

class Game{

private:
	// The window of the game
	sf::RenderWindow gameScreen;

	// The camera of the game
	Camera gameCamera;

	// The clock of the processor
	sf::Clock clock;

	// Fields to control game framerate
	sf::Time timeSinceLastUpdate;
	sf::Time elapsedTime;

	// The player
	Player player;

	// The texture of every alive entity
	TextureSet aliveTexture;

	// The background texture
	TextureSet backgroundTexture;

	// The cutscene texture
	TextureSet cutsceneTexture;

	// The sprite of the background
	sf::Sprite backgroundSprite;

	// The map of the tiles
	//TileMap tileMap;
	Level level;

	// All the colliding tiles
	TileSet theTiles;

	// Background music
	sf::Music bgm;

	// Cutscene
	Cutscene cutscene;

	// Game dimensions
	int gameWidth;
	int gameHeight;

public:
	/**
	 * Constructor.
	 * @param gameWidth the width of the window
	 * @param gameHeight the height of the window
	 * @param gameTitle the title of the window
	 */
	Game(int gameWidth, int gameHeight, std::string gameTitle);

	/**
	 * What to do when the game initializes.
	 */
	void gameStart();

	/**
	 * What to do in the game loop.
	 */
	void gameLoop();

	/**
	 * Move and stop the player if he's colliding with something.
	 */
	void moveNStopPlayer();

	/**
	 * Control the camera, getting it to the player.
	 */
	void controlCamera();

	/**
	 * Restrict the position of the player to not be in 0.5.
	 */
	void restrictPlayerMovement();

	/**
	 * Apply player annimation.
	 */
	void applyPlayerAnimation(Player* player);

	/**
	 * Clear screen and draw it again.
	 */
	void clearNDraw();

	/**
	 * Draw the bullets.
	 */
	void drawBullets();

	/**
	 * Move the bullets.
	 */
	void moveBullets();

	/**
	 * Launch a cutscene.
	 */
	void launchCutscene();

	/**
	 * Get the game width.
	 * @return the game width
	 */
	int getGameWidth();

	/**
	 * Get the game height.
	 * @return the game height
	 */
	int getGameHeight();

	/**
	 * Refresh the position of the background.
	 */
	void refreshBackgroundPos();
};

#endif
