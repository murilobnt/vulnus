#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

// # External
#include <vector>

// # Internal
#include "entities/gamecomponents/enemy.hpp"
#include "structures/tilemap.hpp"
#include "structures/dynamicgrid.hpp"

class Level{
private:
	int w;
	int h;

	int rawW;
	int rawH;

	TileMap tileMap;
	std::vector<Enemy> enemies;
	void loadLevelOne(sf::Texture const& enemiesTexture);

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
