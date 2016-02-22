#include "Player.h"

void Player::increaseHealth(float modifier){
	this->health += modifier;
}

void Player::increaseSpeed(float modifier){
	this->speed += modifier;
}

void Player::decreaseHealth(float modifier){
	this->health -= modifier;
}

void Player::decreaseSpeed(float modifier){
	this->speed -= modifier;
}

Player::Player(float health, float speed, sf::Texture const& texture,
	             int spriteX, int spriteY, int spriteW, int spriteH,
							 float gravity) : AliveEntity::AliveEntity(0, 0, texture, spriteX, spriteY, spriteW, spriteH, gravity) {
	this->bulletControl = false;
	this->invulnerability = false;
	this->health = health;
	this->speed = speed;
	this->level = level;
	this->desaccelerationX = 0.1;
	this->moving = false;
	this->movingRight = false;
	this->movingLeft = false;
	this->facingRight = true;
}

void Player::levelUp(){
	++this->level;
}

void Player::recieveDamage(float modifier){
	this->decreaseHealth(modifier);
}

void Player::recoveryHealth(float modifier){
	this->increaseHealth(modifier);
}

void Player::movePlayer(){
	float jumpDesacceleration = speed/8;
	float jumpAcceleration = speed/6;
	if(isJumping){
		if(movingRight){
			if(movement.x < 0){
				movement.x -= jumpDesacceleration;
			}
			if(movement.x < speed){
				if(movement.x + jumpAcceleration > speed){
					movement.x = speed;
				} else {
					movement.x += jumpAcceleration;
				}
			}
		} else if (movingLeft) {
			if(movement.x > 0){
				movement.x += jumpDesacceleration;
			}
			if(movement.x > -speed){
				if(movement.x - jumpAcceleration < -speed){
					movement.x = -speed;
				} else {
					movement.x -= jumpAcceleration;
				}
			}
		}
		return;
	}
	if(this->movingRight){
		this->movement.x = speed;
	} else if(this->movingLeft){
		this->movement.x = -(speed);
	}
}

void Player::stopPlayer(){
	this->movement.x = 0;
}

void Player::handlePlayerInput(sf::Keyboard::Key key, bool release){
	if(key == sf::Keyboard::K && !this->bulletControl){
		this->theBullets.push_back(Bullet(6.0, sf::Vector2f(this->getSprite().getPosition().x + 16, this->getSprite().getPosition().y + 16), this->facingRight));
		this->bulletControl = true;
	}
	if(key == sf::Keyboard::K && release){
		this->bulletControl = false;
	}

	if(key == sf::Keyboard::W || key == sf::Keyboard::Up || key == sf::Keyboard::Space){
		jump();
		jumpWill = true;
	}

	if(release && (key == sf::Keyboard::W || key == sf::Keyboard::Up || key == sf::Keyboard::Space)){
		if(this->movement.y < 0){
			this->movement.y += 1;
		}
		jumpWill = false;
	}

	if(release && key != sf::Keyboard::W){
		if(key == sf::Keyboard::D || key == sf::Keyboard::Right){
			this->movingRight = false;
			this->moving = false;
		}
		if(key == sf::Keyboard::A  || key == sf::Keyboard::Left){
			this->movingLeft = false;
			this->moving = false;
		}
	} else {
			if(key == sf::Keyboard::D  || key == sf::Keyboard::Right){
				this->moving = true;
				this->movingRight = true;
				this->facingRight = true;
			}
			if(key == sf::Keyboard::A  || key == sf::Keyboard::Left){
				this->moving = true;
				this->movingLeft = true;
				this->facingRight = false;
			}
	}
}

void Player::handleMouseInput(sf::Vector2f mousePosition){
	int mouseX = mousePosition.x;
	int mouseY = mousePosition.y;
	setSpritePosition(sf::Vector2f(mouseX - 16, mouseY - 16));
}

void Player::jump(){
	if(!isJumping && !jumpWill){
		this->movement.y = -7;
		isJumping = true;
	}
}

void Player::desacceleratePlayer(){
	if(this->movement.x > 0 && !this->moving){
		this->movement.x -= this->desaccelerationX;
	}
	if(this->movement.x < 0 && !this->moving){
		this->movement.x += this->desaccelerationX;
	}
	if((this->movement.x > 0 && this->movement.x < 0.1) || (this->movement.x < 0 && this->movement.x > -0.1)){
		stopPlayer();
	}
}

void Player::applyPlayerAnimation(sf::Time* timeSinceLastUpdate){
	if(*timeSinceLastUpdate > this->getAnimationFramerate()){
		*timeSinceLastUpdate -= this->getAnimationFramerate();
		if(this->facingRight){
			if(!this->isJumping){
				if(this->animationRightLoop*32 > 32){
					this->animationRightLoop = 0;
				}
				if(this->movement.x > 0){
					configureSpriteRect(32 * animationRightLoop, 0, 32, 32);
					++this->animationRightLoop;
				} else if(this->movement.x == 0.f){
					configureSpriteRect(32, 0, 32, 32);
				}
			} else {
				configureSpriteRect(0, 0, 32, 32);
			}
		} else if(!this->facingRight){
			if(!this->isJumping){
				if(this->animationLeftLoop*32 > 32){
					this->animationLeftLoop = 0;
				}
				if(this->movement.x < 0){
					configureSpriteRect(32 * animationLeftLoop, 32, 32, 32);
					++this->animationLeftLoop;
				} else if(this->movement.x == 0.f){
					configureSpriteRect(32, 32, 32, 32);
				}
			} else {
				configureSpriteRect(0, 32, 32, 32);
			}
		}
	}
}

void Player::checkHalfOne(){
	float half = fmod(this->getSprite().getPosition().x, 0.5);
	float full = fmod(this->getSprite().getPosition().x, 1.0);

	if((half > 0 && half < 0.1) && full != 0){
		//this->sprite.move(sf::Vector2f(0.2, 0.0));
		moveEntity(sf::Vector2f(0.2, 0.0));
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

	/*for(std::vector<Bullet>::iterator it = this->theBullets.begin(); it != this->theBullets.end(); ++it){
		(*it).moveBullet();
		if((*it).shouldBeDestroyed()){
			//this->theBullets.erase(std::remove(this->theBullets.begin(), this->theBullets.end(), *it), this->theBullets.end());
			//remove the bullet
		}
	}
	*/
	for (uint i = 0; i < this->theBullets.size(); i++) {
        Bullet *cur = &this->theBullets[i];
				cur->moveBullet();
				cur->shouldBeDestroyed(false);
        if(cur->getMarkedForDeath()){
					this->theBullets.erase(this->theBullets.begin() +i);
				}
  }
}
