#include "player.hpp"

Player::Player(float health, float speed, sf::Texture const& texture,
	             int spriteX, int spriteY, int spriteW, int spriteH,
							 float gravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY) : 
AliveEntity::AliveEntity(0, 0, health, speed, texture, spriteX, spriteY, spriteW, spriteH, gravity, spriteInitX, spriteEndX, spriteInitY, spriteEndY) {
	this->bulletControl = false;
	this->invulnerability = false;
	this->level = level;
	this->desaccelerationX = 0.2;
	this->moving = false;
	this->movingRight = false;
	this->movingLeft = false;
	this->facingRight = true;
	this->tryingToJump = false;

	this->font.loadFromFile("fonts/Ubuntu-C.tff");
	this->damageOutput = sf::Text(std::string("-0"), font);

	this->damageOutput.setCharacterSize(20);
   	this->damageOutput.setColor(sf::Color::Red);
}

void Player::levelUp(){
	++this->level;
}

void Player::receiveDamage(float modifier){
	this->reactToDamage(4);
	this->decreaseHealth(modifier);

	this->damageOutput.setString(IntToString::IntToString((int) - comboDamage));

	this->invulnerability = true;
}

void Player::recoveryHealth(float modifier){
	this->increaseHealth(modifier);
}

void Player::movePlayer(){
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
		this->theBullets.push_back(Bullet(16.0, sf::Vector2f(this->getSprite().getPosition().x + 16, this->getSprite().getPosition().y + 16), this->facingRight));
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

std::vector<Bullet> Player::getTheBullets(){
	return this->theBullets;
}

std::vector<Bullet>* Player::getTheBulletsObject(){
	return &this->theBullets;
}

void Player::moveNDeleteBullets(){
	if(this->theBullets.empty()){
		return;
	}

	for (uint i = 0; i < this->theBullets.size(); i++) {
        Bullet *cur = &this->theBullets[i];
				cur->moveBullet();
				cur->shouldBeDestroyed(false);
        if(cur->getMarkedForDeath()){
					this->theBullets.erase(this->theBullets.begin() +i);
				}
  }
}

void Player::rightMovementControl(bool release){
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
	if(release){
		this->movingLeft = false;
		this->moving = false;
	} else {
		this->moving = true;
		this->movingLeft = true;
		this->facingRight = false;
	}
}

bool Player::getInvulnerability(){
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

void Player::updateDamageText(){
	this->damageOutput.setPosition(this->sprite.getPosition().x + this->sprite.getLocalBounds().width/2 - this->damageOutput.getLocalBounds().width/2, this->sprite.getPosition().y - 32);
}

sf::Text Player::getDamageOutput(){
	return this->damageOutput;
}

void Player::drawText(sf::RenderTarget& target){
  target.draw(this->damageOutput);
}