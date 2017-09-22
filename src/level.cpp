#include "entities/level.hpp"

void Level::setLevelWandH(){
	this->rawW = levelLoader.getLevelW();
	this->rawH = levelLoader.getLevelH();

	this->w = rawW * 32;
	this->h = rawH * 32;
}

TileMap Level::getTileMap(){
	return this->tileMap;
}

void Level::loadAnyLevel(Player& player, std::string levelFilePath, sf::Texture const& enemiesTexture, void (Level::*loadLevelFunction)(sf::Texture const&)){
	levelLoader.loadLevel(levelFilePath.c_str());
	setLevelWandH();
	player.setSpritePosition(levelLoader.getPlayerStartPosition());
	(this->*loadLevelFunction)(enemiesTexture);
	levelLoader.deleteLevel();
}

void Level::loadLevelOne(sf::Texture const& enemiesTexture){
	// TODO: Everything could be moved to loadAnyLevel. Need to implement enemies loading from txt file.
	int* collisionTiles = levelLoader.getCollisionTiles();

	tileMap.load("images/tiles.png", sf::Vector2u(32, 32), levelLoader.getLevelArray(), rawW, rawH, collisionTiles, (sizeof(collisionTiles)/sizeof(*collisionTiles)));

	Enemy enemy(448, 480, 30, 1.2, enemiesTexture, 64, 0, 32, 32, 0.2, 64, 96, 0, 32, 15);
	Enemy enemy2(500, 350, 30, 1.2, enemiesTexture, 64, 0, 32, 32, 0.2, 64, 96, 0, 32, 15);

	enemies.push_back(enemy);
	enemies.push_back(enemy2);
}

void Level::loadLevelTwo(sf::Texture const& enemiesTexture){
	int* collisionTiles = levelLoader.getCollisionTiles();

	tileMap.load("images/tiles.png", sf::Vector2u(32, 32), levelLoader.getLevelArray(), rawW, rawH, collisionTiles, (sizeof(collisionTiles)/sizeof(*collisionTiles)));
}

void Level::loadLevel(Player& player, int id, sf::Texture const& enemiesTexture){
	switch (id) {
		case 1:
			loadAnyLevel(player, std::string("data/level1.txt"), enemiesTexture, &Level::loadLevelOne);
		break;
		case 2:
			loadAnyLevel(player, std::string("data/level2.txt"), enemiesTexture, &Level::loadLevelTwo);
		break;
		default:
		break;
	}
}

void Level::drawEnemies(sf::RenderTarget& target){
	for(uint i = 0; i < enemies.size(); i++){
		Enemy cur = enemies.at(i);
		target.draw(cur.getSprite());
	}
}

std::vector<Enemy>* Level::getEnemies(){
	return &this->enemies;
}

DynamicGrid Level::generateDynamicGrid(){
	return this->tileMap.generateDynaGrid();
}

int Level::getW(){
	return this->w;
}

int Level::getH(){
	return this->h;
}