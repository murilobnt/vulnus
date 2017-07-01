#ifndef _GAMESCENE_HPP_
#define _GAMESCENE_HPP_

#include "scene.hpp"

#include "gamescenemanager.hpp"
#include "cutscene.hpp"
#include "player.hpp"
#include "level.hpp"
#include "tileset.hpp"
#include "bullet.hpp"
#include "eventhandler.hpp"
#include "enemy.hpp"
#include "soundtable.hpp"
#include "collisionhandler.hpp"
#include "texturemanager.hpp"

class GameScene : public Scene {
private:
	Cutscene cutscene;
	GameSceneManager gameSceneManager;

	Player player;

	sf::Sprite backgroundSprite;
	Level level;

	EventHandler eventhandler;
	TileSet theTiles;

	SoundTable soundTable;
	sf::RectangleShape playerHealth;

	DynamicGrid dynaGrid;

	CollisionHandler colHandler;

	std::vector<Enemy>* currentEnemies;
	std::vector<Bullet>* playerBulletsRef;

	void controlCamera();
public:
	GameScene(TextureManager& textureManager);

	void start();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void controlCamera(sf::RenderWindow& screen);
	void doOperations();
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);

	void updateLogic();
	void moveNStopPlayer();
	void restrictPlayerMovement();
	void applyPlayerAnimation();
	void moveBullets();
	void launchCutscene();

	void changeLevel();
	void refreshBackgroundPos();
	void applyGravityOnEntities();
	void displayPlayerHealth();
	void updatePlayerHealth();
	void checkEnemyHealth();
};

#endif