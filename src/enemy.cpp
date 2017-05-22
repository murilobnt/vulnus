#include "enemy.hpp"

Enemy::Enemy(int x, int y, float health, float speed, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY) :
AliveEntity::AliveEntity(x, y, health, speed, texture, spriteX, spriteY, spriteW, spriteH, gravity, spriteInitX, spriteEndX, spriteInitY, spriteEndY){
	this->movingRight = false;
	this->movingLeft = false;
}

void Enemy::moveEnemy(sf::Vector2f playerPosition){
	sf::Vector2f myPosition(getSprite().getPosition());

	if(playerIsInRadious(myPosition, playerPosition)){
		if(this->movement.x == 0.f && playerPosition.y < myPosition.y - 1){
			jump();
		}

		if(playerPosition.x < myPosition.x - 1){
			this->movement.x = -(speed);
			facingRight = false;
			movingLeft = true;
			movingRight = false;
		} else if(playerPosition.x > myPosition.x + 1){
			facingRight = true;
			movingLeft = false;
			movingRight = true;
			this->movement.x = speed;
		} else {
			stopEnemy();
		}
	} else {
		stopEnemy();
	}
}

void Enemy::stopEnemy(){
	movingRight = false;
	movingLeft = false;
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

void Enemy::applyRightAnimation(){
	if(spriteInitX + this->animationRightLoop*32 > spriteEndX){
		this->animationRightLoop = 0;
	}
	if(this->movement.x > 0){
		configureSpriteRect(spriteInitX + animationRightLoop*32, spriteInitY, 32, 32);
		++this->animationRightLoop;
	} else if(this->movement.x == 0.f){
		configureSpriteRect(spriteEndX, spriteInitY, 32, 32);
	}
}

void Enemy::applyLeftAnimation(){
	if(this->spriteInitX + this->animationLeftLoop*32 > spriteEndX){
		this->animationLeftLoop = 0;
	}
	if(this->movement.x < 0){
		configureSpriteRect(spriteInitX + animationLeftLoop * 32, spriteEndY, 32, 32);
		++this->animationLeftLoop;
	} else if(this->movement.x == 0.f){
		configureSpriteRect(spriteEndX, spriteEndY, 32, 32);
	}
}

void Enemy::applyEnemyAnimation(){
	if(this->facingRight){
		if(!this->isJumping){
			applyRightAnimation();
		} else {
			configureSpriteRect(spriteInitX, spriteInitY, 32, 32);
		}
	} else if(!this->facingRight){
		if(!this->isJumping){
			applyLeftAnimation();
		} else {
			configureSpriteRect(spriteInitX, spriteEndY, 32, 32);
		}
	}
}