#include "structures/levelloaderfilereader.hpp"

void LevelLoaderFileReader::readFile(std::string fileName){
	in.open(fileName.c_str());
	in >> levelW >> levelH;

	this->level = new int[levelW * levelH];

	for(int i = 0; i < levelH; i++)
		for(int j = 0; j < levelW; j++)
			in >> level[j + (i * levelW)];

	int collisionLength;

	in >> collisionLength;

	this->collision = new int[collisionLength];

	for(int i = 0; i < collisionLength; i++)
		in >> collision[i];

	in.close();
}

int LevelLoaderFileReader::getLevelW(){
	return this->levelW;
}

int LevelLoaderFileReader::getLevelH(){
	return this->levelH;
}

int* LevelLoaderFileReader::getLevelArray(){
	return this->level;
}

int* LevelLoaderFileReader::getCollisionTiles(){
	return this->collision;
}

void LevelLoaderFileReader::loadLevel(std::string fileName){
	readFile(fileName);
}

void LevelLoaderFileReader::deleteLevel(){
	delete[] level;
}