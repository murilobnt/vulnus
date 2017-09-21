#include "entities/level.hpp"

Level::Level(int id, sf::Texture const& enemiesTexture){
	this->rawW = 0;
	this->rawH = 0;

	this->h = 0;
	this->w = 0;

	loadLevel(id, enemiesTexture);
}

void Level::setLevelWandH(){
	this->rawW = levelLoader.getLevelW();
	this->rawH = levelLoader.getLevelH();

	this->w = rawW * 32;
	this->h = rawH * 32;
}

TileMap Level::getTileMap(){
	return this->tileMap;
}

void Level::loadLevelOne(sf::Texture const& enemiesTexture){
	levelLoader.loadLevel("data/level1.txt");
	int* collisionTiles = levelLoader.getCollisionTiles();

	setLevelWandH();

	tileMap.load("images/tiles.png", sf::Vector2u(32, 32), levelLoader.getLevelArray(), rawW, rawH, collisionTiles, (sizeof(collisionTiles)/sizeof(*collisionTiles)));

	levelLoader.deleteLevel();

	Enemy enemy(448, 480, 30, 1.2, enemiesTexture, 64, 0, 32, 32, 0.2, 64, 96, 0, 32, 15);
	Enemy enemy2(500, 350, 30, 1.2, enemiesTexture, 64, 0, 32, 32, 0.2, 64, 96, 0, 32, 15);

	enemies.push_back(enemy);
	enemies.push_back(enemy2);
}

void Level::loadLevel(int id, sf::Texture const& enemiesTexture){
	switch (id) {
		case 1:
			loadLevelOne(enemiesTexture);
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