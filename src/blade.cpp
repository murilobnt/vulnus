#include "blade.hpp"

Blade::Blade(float damage) : 
Weapon::Weapon(damage, SLASH),
sprite(sf::Vector2f(75, 1))
{
	rawDamage = damage;
	bladeControl = false;
	state = FIRST;	
	canDamage = true;
	reach = 50;
}

void Blade::use(AliveEntity& player){
	if(!isActive()){
		if(state == FIRST){
			sprite.setRotation(10);
		}
		if(state == SECOND){
			sprite.setRotation(-10);
		}
		if(state == END){
			sprite.setRotation(0);
		}
		if(player.isFacingRight()){
			this->sprite.setPosition(player.getSpritePosition().x + 32, player.getSpritePosition().y + 16);
			if(state == END){
				player.setSpritePosition(player.getSpritePosition().x + 112, player.getSpritePosition().y);
			}
		} else {
			sprite.rotate(180);
			this->sprite.setPosition(player.getSpritePosition().x, player.getSpritePosition().y + 16);
			if(state == END){
				player.setSpritePosition(player.getSpritePosition().x - 112, player.getSpritePosition().y);
			}
		}

		setActive(true);
		sprite.setSize(sf::Vector2f(0, 1));
	}
}

void Blade::update(){
	if(isActive()){
		if(state == END){
			reach = 80;
		}

		sf::Vector2f spriteSize = sprite.getSize();

		if(spriteSize.x >= reach){
			bladeControl = !bladeControl;
		}

		if(!bladeControl){
			spriteSize.x = spriteSize.x + 15;
			sprite.setSize(spriteSize);

		} else if(state == END) {
			sprite.setSize(sf::Vector2f(0, 5));
		} else {
			spriteSize.x = spriteSize.x - 15;
			sprite.setSize(spriteSize);
		}

		if(spriteSize.x <= 0.f){
			bladeControl = false;
			setActive(false);
			canDamage = true;

			state = (BladeState)((int)state + 1);
			setDamage(getDamage() + (getDamage()/5));

			if(state > END){
				setDamage(rawDamage);
				state = FIRST;
				reach = 50;
			}
		}
	}
}

bool Blade::isCollidingWithEnemy(const AliveEntity& enemy){
	if(sprite.getGlobalBounds().intersects(enemy.getSpriteGlobalBounds()) && canDamage){
		canDamage = false;
		return true;
	}
	return false;
}

bool Blade::isCollidingWithEnvironment(const TileGrid& grid){
	return false;
}

void Blade::draw(sf::RenderTarget& target){
	target.draw(this->sprite);
}