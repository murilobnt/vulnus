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
#include "camera.hpp"
#include "player.hpp"
#include "texturemanager.hpp"
#include "level.hpp"
#include "tileset.hpp"
#include "bullet.hpp"
#include "cutscene.hpp"
#include "eventhandler.hpp"
#include "enemy.hpp"
#include "clockhandler.hpp"
#include "generictimehandler.hpp"
#include "dynamicgrid.hpp"
#include "soundtable.hpp"
#include "collisionhandler.hpp"
#include "timehandlers.hpp"

class Game{

private:
	// The window of the game
	sf::RenderWindow gameScreen;

	// The camera of the game
	Camera gameCamera;

	sf::Time ups;

	// The clock of the processor
	sf::Clock clock;

	// Fields to control game framerate
	sf::Time timeSinceLastUpdate;
	sf::Time fpsTime;
	
	sf::Time elapsedTime;

	sf::Font font;

	// The player
	Player player;

	EventHandler eventhandler;

	TextureManager textureManager;

	// The sprite of the background
	sf::Sprite backgroundSprite;

	// The map of the tiles
	//TileMap tileMap;
	Level level;

	// All the colliding tiles
	TileSet theTiles;

	// Background music
	SoundTable soundTable;

	sf::RectangleShape playerHealth;

	DynamicGrid dynaGrid;

	CollisionHandler colHandler;

	// Cutscene
	Cutscene cutscene;

	// Game dimensions
	int gameWidth;
	int gameHeight;

	std::vector<Enemy>* currentEnemies;

	ClockHandler clockHandler;

	GenericTimeHandler gameFrequency;

	/*GenericTimeHandler* gameFrequency;
	GenericTimeHandler* playerAnimation;
	GenericTimeHandler* playerSound;
	GenericTimeHandler* playerInvulnerability;
	GenericTimeHandler* playerInvulnerabilityAnimation;
	GenericTimeHandler* entityComboDelimeter;*/

	std::vector<Bullet>* playerBulletsRef;

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

	void processEvents();

	/**
	 * What to do in the game loop.
	 */
	void updateLogic();

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
	void applyPlayerAnimation();

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

	void changeLevel();

	void applyGravityOnEntities();

	void displayPlayerHealth();

	void updatePlayerHealth();

	void handleTimeActions();

	void checkEnemyHealth();
};

#endif
