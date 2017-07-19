#include "entities/weapon/polargun.hpp"

PolarGun::PolarGun(float damage) : Weapon::Weapon(damage, RANGED){
}

void PolarGun::use(AliveEntity& player){
	this->bullets.push_back(Bullet(16.0, sf::Vector2f(player.getSpritePosition().x + 16, player.getSpritePosition().y + 16), player.isFacingRight()));
}

void PolarGun::update(){
	if(bullets.empty()){
		return;
	}

	for (uint i = 0; i < bullets.size(); i++) {
		Bullet *cur = &bullets[i];

		cur->moveBullet();
		cur->shouldBeDestroyed(false);
		
		if(cur->getMarkedForDeath()){
			bullets.erase(bullets.begin() +i);
		}
	}
}

bool PolarGun::isCollidingWithEnemy(const AliveEntity& enemy){
	if(bullets.empty()){
		return false;
	}

	for(std::vector<Bullet>::iterator bIt = bullets.begin(); bIt != bullets.end(); ++bIt){
		if((*bIt).getBullet().getGlobalBounds().intersects(enemy.getSpriteGlobalBounds())){
			(*bIt).shouldBeDestroyed(true);
			return true;
		}
	}

	return false;
}

bool PolarGun::isCollidingWithEnvironment(const TileGrid& grid){
	for(std::vector<Bullet>::iterator bIt = bullets.begin(); bIt != bullets.end(); ++bIt){
		std::vector<Unity> unities = grid.getUnitiesOnPosition((*bIt).getBullet().getPosition());

	    for(std::vector<Unity>::iterator unitiesIt = unities.begin(); unitiesIt != unities.end(); ++unitiesIt){
	      Unity unity = *unitiesIt;

	      for(std::vector<Tile>::iterator it = unity.tiles.begin(); it != unity.tiles.end(); ++it){
	        sf::FloatRect boundingBox = (*bIt).getBullet().getGlobalBounds();
	        
	        if((*it).getTileRect().intersects(boundingBox)){
	          (*bIt).shouldBeDestroyed(true);
	        }
	      }
	    }
	}
}

void PolarGun::draw(sf::RenderTarget& target){
	if(bullets.empty()){
		return;
	}

	for(std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it){
		target.draw((*it).getBullet());
	}
}