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

void Level::loadAnyLevel(Player& player, std::string levelFilePath, sf::Texture const& enemiesTexture){
	levelLoader.loadLevel(levelFilePath.c_str());
	setLevelWandH();
	int* collisionTiles = levelLoader.getCollisionTiles();
	tileMap.load("images/tiles.png", sf::Vector2u(32, 32), levelLoader.getLevelArray(), rawW, rawH, collisionTiles, (sizeof(collisionTiles)/sizeof(*collisionTiles)));
	player.setSpritePosition(levelLoader.getPlayerStartPosition());
	levelLoader.deleteLevel();
}

void Level::loadLevel(Player& player, int id, sf::Texture const& enemiesTexture){
	switch (id) {
		case 1:
			loadAnyLevel(player, std::string("data/level1.txt"), enemiesTexture);
		break;
		case 2:
			loadAnyLevel(player, std::string("data/level2.txt"), enemiesTexture);
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