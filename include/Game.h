#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Camera.h"
#include "Player.h"
#include "TextureSet.h"
#include "TileMap.h"
#include "TileSet.h"
#include "Bullet.h"
#include "Cutscene.h"

class Game{

private:
	sf::RenderWindow gameScreen;
	Camera camera;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time elapsedTime;

	Player player;
	TextureSet aliveTexture;
	TextureSet backgroundTexture;
	TextureSet cutsceneTexture;
	sf::Sprite backgroundSprite;
	TileMap tileMap;
	TileSet theTiles;

	//sf::Music bgm;

	Cutscene cutscene;
	//CutscenesDatabase cutscenesData;

	int gameWidth;
	int gameHeight;

public:
	Game(int gameWidth, int gameHeight, std::string gameTitle);
	void gameStart();
	void gameLoop();
	void viewInitializer(int x, int y, int w, int h);
	void viewZoom();
	void moveNStopPlayer();
	void controlCamera();
	void restrictPlayerMovement();
	void applyPlayerAnimation(Player* player);
	void clearNDraw();
	void drawBullets();
	void moveBullets();
	void launchCutscene();
	int getGameWidth();
	int getGameHeight();
	void refreshBackgroundPos();
};

#endif
