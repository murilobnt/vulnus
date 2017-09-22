#ifndef _LEVELLOADERFILEREADER_HPP_
#define _LEVELLOADERFILEREADER_HPP_

#include <fstream>
#include <SFML/Graphics.hpp>

#include "generics/filereader.hpp"

class LevelLoaderFileReader : public FileReader {
private:
	std::ifstream in;

	int levelW;
	int levelH;

	int* level;
	int* collision;
	sf::Vector2f playerStartPosition;

	void readFile(std::string fileName);

public:
	int getLevelW();
	int getLevelH();
	int* getLevelArray();
	int* getCollisionTiles();
	sf::Vector2f getPlayerStartPosition();

	void loadLevel(std::string fileName);
	void deleteLevel();
};

#endif