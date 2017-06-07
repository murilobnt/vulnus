#include "collisionhandler.hpp"

CollisionHandler::CollisionHandler(DynamicGrid dynaGrid){
	this->dynaGrid = dynaGrid;
}

CollisionHandler::CollisionHandler(){
	
}

bool CollisionHandler::collisionBetweenPAndE(const Player& player, const Enemy& enemy) const{
	if(player.getQuad() == enemy.getQuad()){
		if(player.getSprite().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())){
			if(Collision::PixelPerfectTest(player.getSprite(), enemy.getSprite()) && !player.getInvulnerability()){
				return true;
			}
		}
	}

	return false;
}

bool CollisionHandler::collisionBetweenBAndE(const Bullet& bullet, const Enemy& enemy) const{
	if(bullet.getBullet().getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())){
		return true;
	}
	
	return false;
}