#include "entities/parallaxbackground.hpp"

ParallaxBackground::ParallaxBackground(sf::Texture& texture, double movementFactor){
	bg.setTexture(texture);
	bg.setPosition(sf::Vector2f(0,0));
	this->movementFactor = movementFactor;
}

double ParallaxBackground::getMovementFactor(){
	return this->movementFactor;
}

sf::Sprite* ParallaxBackground::getSpriteRef(){
	return &this->bg;
}

sf::Sprite& ParallaxBackground::getSprite(){
	return this->bg;
}

void ParallaxBackground::initLevelWandH(int levelW, int levelH){
	setLevelW(levelW);
	setLevelH(levelH);
	bg.setTextureRect(sf::IntRect(0, 0, (levelW) + ((levelW)*movementFactor), levelH));
}

void ParallaxBackground::setLevelW(int levelW){
	this->levelW = levelW;
}

void ParallaxBackground::setLevelH(int levelH){
	this->levelH = levelH;
}