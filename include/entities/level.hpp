#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

// # External
#include <vector>
#include <iostream>
#include <functional>

// # Internal
#include "entities/gamecomponents/enemy.hpp"
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

	void loadLevelOne(sf::Texture const& enemiesTexture);
	void setLevelWandH();

public:
	Level(int id, sf::Texture const& enemiesTexture);
	TileMap getTileMap();
	void loadLevel(int id, sf::Texture const& enemiesTexture);
	void drawEnemies(sf::RenderTarget& target);
	std::vector<Enemy>* getEnemies();
	DynamicGrid generateDynamicGrid();

	int getW();
	int getH();
};

#endif
