#include "spritedentity.hpp"

SpritedEntity::SpritedEntity(sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH){
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

void SpritedEntity::setSpriteColor(sf::Color color){
	this->sprite.setColor(color);
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