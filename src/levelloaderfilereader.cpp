#include "structures/levelloaderfilereader.hpp"

void LevelLoaderFileReader::openFileStream(std::string fileName){
	in.open(fileName.c_str());
}

void LevelLoaderFileReader::closeFileStream(){
	in.close();
}

void LevelLoaderFileReader::loadTileMap(){
	if(!in.is_open())
		return;

	in >> levelW >> levelH;

	this->level = new int[levelW * levelH];

	for(int i = 0; i < levelH; i++)
		for(int j = 0; j < levelW; j++)
			in >> level[j + (i * levelW)];
}

void LevelLoaderFileReader::loadCollisionTiles(){
	if(!in.is_open())
		return;

	int collisionLength;

	in >> collisionLength;

	this->collision = new int[collisionLength];

	for(int i = 0; i < collisionLength; i++)
		in >> collision[i];
}

void LevelLoaderFileReader::loadPlayerPosition(){
	if(!in.is_open())
		return;

	float playerStartPosX, playerStartPosY;

	in >> playerStartPosX >> playerStartPosY;

	this->playerStartPosition = sf::Vector2f(playerStartPosX, playerStartPosY);
}

void LevelLoaderFileReader::loadEnemies(){
	if(!in.is_open())
		return;

	enemies.clear();

	int numberOfEnemies;

	in >> numberOfEnemies;

	for(int i = 0; i < numberOfEnemies; i++){
		int enX, enY;

		in >> enX >> enY;

		enemies.push_back(Enemy(enX, enY, 30, 1.2, this->enemiesTexture, 64, 0, 32, 32, 0.2, 64, 96, 0, 32, 15));
	}
}

void LevelLoaderFileReader::loadTransitionPoints(){
	if(!in.is_open())
		return;

	int numberOfTransitionPoints;

	in >> numberOfTransitionPoints;
}

void LevelLoaderFileReader::loadTransitionEdges(){
	if(!in.is_open())
		return;

	int numberOfTransitionEdges;

	for(int i = 0; i < numberOfTransitionEdges; i++){
		int levelEdge, destination;

		in >> levelEdge;
		LevelEdge currentLevelEdge = static_cast<LevelEdge>(levelEdge);
	}
}

void LevelLoaderFileReader::loadLevel(){
	loadTileMap();
	loadCollisionTiles();
	loadEnemies();
	loadPlayerPosition();
}

void LevelLoaderFileReader::setEnemiesTexture(sf::Texture const& enemiesTexture){
	this->enemiesTexture = enemiesTexture;
}

std::vector<Enemy> LevelLoaderFileReader::getEnemies(){
	return this->enemies;
}

void LevelLoaderFileReader::readFile(std::string fileName){
	openFileStream(fileName);
	loadLevel();
	closeFileStream();
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

sf::Vector2f LevelLoaderFileReader::getPlayerStartPosition(){
	return this->playerStartPosition;
}

void LevelLoaderFileReader::deleteLevel(){
	delete[] level;
}