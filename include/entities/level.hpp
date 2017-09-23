#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

// # External
#include <vector>
#include <iostream>
#include <functional>

// # Internal
#include "entities/gamecomponents/enemy.hpp"
#include "entities/gamecomponents/player.hpp"
#include "structures/tilemap.hpp"
#include "structures/dynamicgrid.hpp"
#include "structures/levelloaderfilereader.hpp"

class Level{
private:
	int w;
	int h;

	int rawW;
	int rawH;

	TileMap tileMap;
	std::vector<Enemy> enemies;
	
	LevelLoaderFileReader levelLoader;

	void loadAnyLevel(Player& player, std::string levelFilePath, sf::Texture const& enemiesTexture);
	void setLevelWandH();

public:
	TileMap getTileMap();
	void loadLevel(Player& player, int id, sf::Texture const& enemiesTexture);
	void drawEnemies(sf::RenderTarget& target);
	std::vector<Enemy>* getEnemies();
	DynamicGrid generateDynamicGrid();

	int getW();
	int getH();
};

#endif
