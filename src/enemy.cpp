#include "enemy.hpp"

Enemy::Enemy(int x, int y, float health, float speed, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY, float damage) :
AliveEntity::AliveEntity(x, y, health, speed, texture, spriteX, spriteY, spriteW, spriteH, gravity, spriteInitX, spriteEndX, spriteInitY, spriteEndY){
	this->movingRight = false;
	this->movingLeft = false;
	this->damage = damage;
	setComboDelimeter(1);
}

void Enemy::moveEnemy(sf::Vector2f playerPosition){
	sf::Vector2f myPosition(getSpritePosition());

	if(playerIsInRadious(myPosition, playerPosition)){
		if(this->movement.x == 0.f && playerPosition.y < myPosition.y - 1){
			jump();
		}

		if(playerPosition.x < myPosition.x - 1){
			facingRight = false;
			movingLeft = true;
			movingRight = false;
			if(this->movement.x > -(speed)){
				this->movement.x -= 0.2;
			} else {
				this->movement.x = -(speed);
			}
		} else if(playerPosition.x > myPosition.x + 1){
			facingRight = true;
			movingLeft = false;
			movingRight = true;

			if(this->movement.x < speed){
				this->movement.x += 0.2;
			} else{
				this->movement.x = speed;
			}
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

bool Enemy::playerIsInRadious(sf::Vector2f myPosition, sf::Vector2f playerPosition) const{
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
	if(getSpriteInitX() + this->animationRightLoop*32 > getSpriteEndX()){
		this->animationRightLoop = 0;
	}
	if(this->movement.x > 0){
		configureSpriteRect(getSpriteInitX() + animationRightLoop*32, getSpriteInitY(), 32, 32);
		++this->animationRightLoop;
	} else if(this->movement.x == 0.f){
		configureSpriteRect(getSpriteEndX(), getSpriteInitY(), 32, 32);
	}
}

void Enemy::applyLeftAnimation(){
	if(this->getSpriteInitX() + this->animationLeftLoop*32 > getSpriteEndX()){
		this->animationLeftLoop = 0;
	}
	if(this->movement.x < 0){
		configureSpriteRect(getSpriteInitX() + animationLeftLoop * 32, getSpriteEndY(), 32, 32);
		++this->animationLeftLoop;
	} else if(this->movement.x == 0.f){
		configureSpriteRect(getSpriteEndX(), getSpriteEndY(), 32, 32);
	}
}

void Enemy::applyEnemyAnimation(){
	if(this->facingRight){
		if(!this->isJumping){
			applyRightAnimation();
		} else {
			configureSpriteRect(getSpriteInitX(), getSpriteInitY(), 32, 32);
		}
	} else if(!this->facingRight){
		if(!this->isJumping){
			applyLeftAnimation();
		} else {
			configureSpriteRect(getSpriteInitX(), getSpriteEndY(), 32, 32);
		}
	}
}

float Enemy::getDamage() const{
	return this->damage;
}

void Enemy::setDamage(float damage){
	this->damage = damage;
}

void Enemy::receiveDamage(float damage){
	this->reactToDamage(0);
	this->decreaseHealth(damage);
}

void Enemy::reactToDamage(float modifier){
	if(this->facingRight){
		this->movement.x = -1;
	} else {
		this->movement.x = 1;
	}

	if(!isJumping){
		this->movement.y = -modifier;
		isJumping = true;
	}
}