#include "blade.hpp"

Blade::Blade(float damage) : 
Weapon::Weapon(damage, SLASH),
sprite(sf::Vector2f(75, 5))
{
	rawDamage = damage;
	bladeControl = false;
	state = FIRST;
	attackLeft = false;
	canDamage = true;
	reach = 50;
}

void Blade::use(AliveEntity& player){
	if(!isActive()){
		//this->comboTime.resetLastUpdate();

		if(player.isFacingRight()){
			this->sprite.setPosition(player.getSprite().getPosition().x + 32, player.getSprite().getPosition().y + 16);
			if(state == END){
				player.setSpritePosition(player.getSprite().getPosition().x + 112, player.getSprite().getPosition().y);
			}
		} else {
			attackLeft = true;
			this->sprite.setPosition(player.getSprite().getPosition().x, player.getSprite().getPosition().y + 16);
			if(state == END){
				player.setSpritePosition(player.getSprite().getPosition().x - 112, player.getSprite().getPosition().y);
			}
		}

		setActive(true);
		sprite.setSize(sf::Vector2f(0, 5));
	}
}

void Blade::update(){
	/*if(comboTime.timeToUpdate()){
		std::cout << "entrou aqui" << std::endl;
		state = FIRST;
	}*/

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

			if(attackLeft){
				sf::Vector2f spritePos = sprite.getPosition();
				spritePos.x = spritePos.x - 15;
				sprite.setPosition(spritePos);
			}

			sprite.setSize(spriteSize);

		} else if(state == END) {
			sprite.setSize(sf::Vector2f(0, 5));
		} else {
			spriteSize.x = spriteSize.x - 15;

			if(attackLeft){
				sf::Vector2f spritePos = sprite.getPosition();
				spritePos.x = spritePos.x + 15;
				sprite.setPosition(spritePos);
			}

			sprite.setSize(spriteSize);
		}

		if(spriteSize.x <= 0.f){
			bladeControl = false;
			attackLeft = false;
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
	if(sprite.getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds()) && canDamage){
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