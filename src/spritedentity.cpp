#include "spritedentity.hpp"

SpritedEntity::SpritedEntity(sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY){
	this->spriteInitX = spriteInitX;
	this->spriteEndX = spriteEndX;
	this->spriteInitY = spriteInitY;
	this->spriteEndY = spriteEndY;

	this->sprite.setTexture(texture);
	configureSpriteRect(spriteX, spriteY, spriteW, spriteH);
}

void SpritedEntity::configureSpriteRect(int x, int y, int w, int h){
    this->sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

void SpritedEntity::setSpritePosition(sf::Vector2f position){
	this->sprite.setPosition(position);
}

void SpritedEntity::setSpritePosition(float x, float y){
	this->sprite.setPosition(x, y);
}

void SpritedEntity::moveSprite(sf::Vector2f movement){
	this->sprite.move(movement);
}

sf::Sprite SpritedEntity::getSprite() const {
	return this->sprite;
}

sf::Vector2f SpritedEntity::getSpritePosition() const {
	return this->sprite.getPosition();
}

sf::FloatRect SpritedEntity::getSpriteGlobalBounds() const {
	return this->sprite.getGlobalBounds();
}

sf::FloatRect SpritedEntity::getSpriteLocalBounds() const {
	return this->sprite.getLocalBounds();
}

int SpritedEntity::getSpriteInitX() const{
	return this->spriteInitX;
}

int SpritedEntity::getSpriteEndX() const{
	return this->spriteEndX;
}

int SpritedEntity::getSpriteInitY() const{
	return this->spriteInitY;
}

int SpritedEntity::getSpriteEndY() const{
	return this->spriteEndY;
}