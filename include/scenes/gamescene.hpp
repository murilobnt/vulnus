#ifndef _GAMESCENE_HPP_
#define _GAMESCENE_HPP_

#include "generics/scene.hpp"

#include "scenes/gamescenemanager.hpp"

#include "enums/daytime.hpp"

#include "entities/cutscene/cutscene.hpp"
#include "entities/gamecomponents/player.hpp"
#include "entities/level.hpp"
#include "entities/gamecomponents/enemy.hpp"

#include "structures/tileset.hpp"
#include "structures/bullet.hpp"
#include "structures/eventhandler.hpp"
#include "entities/soundtable.hpp"
#include "structures/collisionhandler.hpp"
#include "structures/texturemanager.hpp"
#include "structures/ingametime.hpp"
#include "structures/colorgetter.hpp"

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
	sf::Font font;

	InGameTime gameTime;

	CollisionHandler colHandler;

	std::vector<Enemy>* currentEnemies;
	std::vector<Bullet>* playerBulletsRef;

	void controlCamera();
public:
	GameScene(TextureManager& textureManager, SSceneManager* sceneManager);

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

	void updateLogic();
	void moveNStopPlayer();
	void restrictPlayerMovement();
	void applyPlayerAnimation();
	void moveBullets();
	void launchCutscene();

	void changeLevel();
	void refreshBackgroundPos();
	void refreshTimePos();
	void applyGravityOnEntities();
	void displayPlayerHealth();
	void updatePlayerHealth();
	void checkEnemyHealth();
};

#endif