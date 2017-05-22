#include "enemy.hpp"

Enemy::Enemy(int x, int y, float health, float speed, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY) :
AliveEntity::AliveEntity(x, y, health, speed, texture, spriteX, spriteY, spriteW, spriteH, gravity, spriteInitX, spriteEndX, spriteInitY, spriteEndY){

}

void Enemy::moveEnemy(sf::Vector2f playerPosition){
	sf::Vector2f myPosition(getSprite().getPosition());

	if(playerIsInRadious(myPosition, playerPosition)){
		if(this->movement.x == 0.f && playerPosition.y < myPosition.y - 1){
			jump();
		}

		if(playerPosition.x < myPosition.x - 1){
			this->movement.x = -(speed);
		} else if(playerPosition.x > myPosition.x + 1){
			this->movement.x = speed;
		} else {
			stopEnemy();
		}
	} else {
		stopEnemy();
	}
}

void Enemy::stopEnemy(){
	this->movement.x = 0;
}

void Enemy::jump(){
	if(!isJumping){
		this->movement.y = -5;
		isJumping = true;
	}
}

bool Enemy::playerIsInRadious(sf::Vector2f myPosition, sf::Vector2f playerPosition){
	int rad = 7;
	int raw = rad * 32;

	if(playerPosition.x > myPosition.x - raw &&
	   playerPosition.x < myPosition.x + raw &&
	   playerPosition.y > myPosition.y - raw &&
	   playerPosition.y < myPosition.y + raw){
	   	return true;
	}
	return false;
}