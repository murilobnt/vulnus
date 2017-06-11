#include "polargun.hpp"

PolarGun::PolarGun(float damage) : Weapon::Weapon(damage, RANGED){
}

void PolarGun::use(Player& player){
	this->bullets.push_back(Bullet(16.0, sf::Vector2f(player.getSprite().getPosition().x + 16, player.getSprite().getPosition().y + 16), player.isFacingRight()));
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

bool PolarGun::isCollindingWithEnemy(const Enemy& enemy){
	if(bullets.empty()){
		return false;
	}

	for(std::vector<Bullet>::iterator bIt = bullets.begin(); bIt != bullets.end(); ++bIt){
		if((*bIt).getBullet().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())){
			return true;
		}
	}

	return false;
}