#ifndef _LEVELLOADERFILEREADER_HPP_
#define _LEVELLOADERFILEREADER_HPP_

#include <fstream>

#include "generics/filereader.hpp"

class LevelLoaderFileReader : public FileReader {
private:
	std::ifstream in;

	int levelW;
	int levelH;

	int* level;
	int* collision;

	void readFile(std::string fileName);

public:
	int getLevelW();
	int getLevelH();
	int* getLevelArray();
	int* getCollisionTiles();

	void loadLevel(std::string fileName);
	void deleteLevel();
};

#endif