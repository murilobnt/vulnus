#ifndef _LEVELLOADERFILEREADER_HPP_
#define _LEVELLOADERFILEREADER_HPP_

#include <fstream>
#include <SFML/Graphics.hpp>

#include "generics/filereader.hpp"
#include "entities/gamecomponents/enemy.hpp"
#include "enums/leveledge.hpp"

class LevelLoaderFileReader : public FileReader {
private:
	std::ifstream in;

	int levelW;
	int levelH;

	int* level;
	int* collision;

	sf::Texture enemiesTexture;
	std::vector<Enemy> enemies;
	
	sf::Vector2f playerStartPosition;

	void openFileStream(std::string fileName);
	void closeFileStream();

	void loadLevel();

	void loadTileMap();
	void loadCollisionTiles();
	void loadPlayerPosition();
	void loadEnemies();
	void loadTransitionEdges();
	void loadTransitionPoints();

public:
	int getLevelW();
	int getLevelH();
	int* getLevelArray();
	int* getCollisionTiles();
	sf::Vector2f getPlayerStartPosition();

	void setEnemiesTexture(sf::Texture const& enemiesTexture);
	std::vector<Enemy> getEnemies();

	void readFile(std::string fileName);
	void deleteLevel();
};

#endif