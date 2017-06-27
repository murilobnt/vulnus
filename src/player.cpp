#include "player.hpp"

Player::Player(float health, float speed, sf::Texture const& texture,
	             int spriteX, int spriteY, int spriteW, int spriteH,
							 float gravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY) : 
AliveEntity::AliveEntity(0, 0, health, speed, texture, spriteX, spriteY, spriteW, spriteH, gravity, spriteInitX, spriteEndX, spriteInitY, spriteEndY),
ranged(5),
blade(10),
animation(sf::seconds(1.f / 10.f)),
footstep(sf::seconds(1.f / 5.f)),
invulnerabilityTime(sf::seconds(2)),
invulnerabilityAnimation(sf::seconds(1.f / 15.f)) {
	this->bulletControl = false;
	this->invulnerability = false;
	this->level = level;
	this->desaccelerationX = 0.2;
	this->moving = false;
	this->movingRight = false;
	this->movingLeft = false;
	this->facingRight = true;
	this->tryingToJump = false;

	this->weaponId = 0;
}

void Player::levelUp(){
	++this->level;
}

void Player::receiveDamage(float modifier){
	this->reactToDamage(4);
	this->decreaseHealth(modifier);

	this->invulnerability = true;
}

void Player::recoveryHealth(float modifier){
	this->increaseHealth(modifier);
}

void Player::movePlayer(){
	if(blade.isActive() && !isJumping){
		this->movement.x = 0;
		return;
	}

	if(this->movingRight){
		if(this->movement.x < speed){
			this->movement.x += 0.2;
		} else{
			this->movement.x = speed;
		}
	} else if(this->movingLeft){
		if(this->movement.x > -(speed)){
			this->movement.x -= 0.2;
		} else {
			this->movement.x = -(speed);
		}
	}
}

void Player::stopPlayer(){
	this->movement.x = 0;
}

void Player::shoot(bool release){
	if(!this->bulletControl){
		if(weaponId == 0){
			this->ranged.use(*this);
		} else {
			this->blade.use(*this);
		}
		this->bulletControl = true;
	} else if(release){
		this->bulletControl = false;
	}
}

void Player::teleport(int mX, int mY){
	setSpritePosition(sf::Vector2f(mX - 16, mY - 16));
}

void Player::jump(){
	if(!isJumping && !tryingToJump){
		this->movement.y = -7;
		isJumping = true;
	}
	tryingToJump = true;
}

void Player::stopJump(){
	if(this->movement.y < 0){
		this->movement.y = -1;
	}
	this->tryingToJump = false;
}

void Player::run(bool shouldRun){
	// Note: Implement speed modifier
	if(!shouldRun){
		// Note: Should be: this->speed += this->speedmod;
		this->speed += 3;
	} else {
		this->speed = this->originalSpeed;
	}
}

void Player::desacceleratePlayer(){
	if(this->movement.x > 0 && !this->moving){
		this->movement.x -= this->desaccelerationX;
	}
	if(this->movement.x < 0 && !this->moving){
		this->movement.x += this->desaccelerationX;
	}
	if((this->movement.x > 0 && this->movement.x < 0.2) || (this->movement.x < 0 && this->movement.x > -0.2)){
		stopPlayer();
	}
}

void Player::applyRightAnimation(){
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

void Player::applyLeftAnimation(){
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

void Player::applyPlayerAnimation(){
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

void Player::rightMovementControl(bool release){
	if(this->movingLeft){
		return;
	}

	if(release){
		this->movingRight = false;
		this->moving = false;
	} else {
		this->moving = true;
		this->movingRight = true;
		this->facingRight = true;
	}
}

void Player::leftMovementControl(bool release){
	if(this->movingRight){
		return;
	}

	if(release){
		this->movingLeft = false;
		this->moving = false;
	} else {
		this->moving = true;
		this->movingLeft = true;
		this->facingRight = false;
	}
}

bool Player::getInvulnerability() const{
	return this->invulnerability;
}

void Player::setInvulnerability(bool invulnerability){
	this->invulnerability = invulnerability;
}

void Player::reactToDamage(float modifier){
	if(this->facingRight){
		this->movement.x = -5;
	} else {
		this->movement.x = 5;
	}

	if(!isJumping){
		this->movement.y = -modifier;
		isJumping = true;
	}
}

Weapon& Player::getPlayerWeapon(){
	if(this->weaponId == 0){
		return this->ranged;
	}
	return this->blade;
}

void Player::changeWeapon(){
	if(weaponId == 0){
		weaponId = 1;
	} else if(weaponId == 1){
		weaponId = 0;
	}
}

GenericTimeHandler& Player::getTimeHandler(int index){
	switch(index){
		case 0:
			return this->animation;
		break;
		case 1:
			return this->footstep;
		break;
		case 2:
			return this->invulnerabilityTime;
		break;
		case 3:
			return this->invulnerabilityAnimation;
		break;
		default:
			return this->animation;
		break;
	}
}