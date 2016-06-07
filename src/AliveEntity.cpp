#include "AliveEntity.h"
#include "TextureSet.h"

void AliveEntity::increaseHealth(float modifier){
	this->health += modifier;
}

void AliveEntity::increaseSpeed(float modifier){
	this->speed += modifier;
}

void AliveEntity::decreaseHealth(float modifier){
	this->health -= modifier;
}

void AliveEntity::decreaseSpeed(float modifier){
	this->speed -= modifier;
}

void AliveEntity::setSprite(sf::Texture const& texture){
	this->sprite.setTexture(texture);
}

void AliveEntity::configureSpriteRect(int x, int y, int w, int h){
    this->sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

sf::Sprite AliveEntity::getSprite(){
	return this->sprite;
}

void AliveEntity::setSpritePosition(sf::Vector2f position){
	this->sprite.setPosition(position);
}

void AliveEntity::moveEntity(sf::Vector2f movement){
	this->sprite.move(movement);
}

AliveEntity::AliveEntity(int x, int y, float health, float speed, sf::Texture const& texture,
	                       int spriteX, int spriteY, int spriteW, int spriteH,
											   float entityGravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY){
	this->movement = sf::Vector2f(0.f, 0.f);
	this->sprite.setPosition(x, y);

	this->entityGravity = entityGravity;
	this->isJumping = true;
	this->jumpWill = false;
	this->animationLeftLoop = 0;
	this->animationRightLoop = 0;

	this->health = health;
	this->originalSpeed = speed;
	this->speed = speed;

	this->spriteInitX = spriteInitX;
	this->spriteEndX = spriteEndX;
	this->spriteInitY = spriteInitY;
	this->spriteEndY = spriteEndY;

	setSprite(texture);
	configureSpriteRect(spriteX, spriteY, spriteW, spriteH);
	setAnimationFramerate(10);
}

void AliveEntity::moveEntity(){
	this->sprite.move(movement);
}

sf::Vector2f AliveEntity::getMovement(){
	return this->movement;
}

void AliveEntity::setMovementX(float x){
	this->movement.x = x;
}

void AliveEntity::setMovementY(float y){
	this->movement.y = y;
}

void AliveEntity::applyGravity(){
		this->movement.y += entityGravity;
}

void AliveEntity::setAnimationFramerate(float fps){
	this->spriteAnimationFramerate = sf::seconds(1.f/fps);
}

sf::Time AliveEntity::getAnimationFramerate(){
	return this->spriteAnimationFramerate;
}

bool AliveEntity::getIsJumping(){
	return this->isJumping;
}

void AliveEntity::setIsJumping(bool jumping){
	this->isJumping = jumping;
}

float AliveEntity::getGravity(){
	return this->entityGravity;
}

void AliveEntity::setSpritePosition(float x, float y){
	this->sprite.setPosition(x, y);
}
