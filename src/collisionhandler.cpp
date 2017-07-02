#include "collisionhandler.hpp"

CollisionHandler::CollisionHandler(DynamicGrid dynaGrid){
	this->dynaGrid = dynaGrid;
}

CollisionHandler::CollisionHandler(){
	
}

bool CollisionHandler::collisionBetweenPAndE(const Player& player, const Enemy& enemy) const{
	if(player.getQuad() == enemy.getQuad()){
		if(player.getSpriteGlobalBounds().intersects(enemy.getSpriteGlobalBounds())){
			if(Collision::PixelPerfectTest(player.getSprite(), enemy.getSprite()) && !player.getInvulnerability()){
				return true;
			}
		}
	}

	return false;
}

bool CollisionHandler::collisionBetweenBAndE(const Bullet& bullet, const Enemy& enemy) const{
	if(bullet.getBullet().getGlobalBounds().intersects(enemy.getSpriteGlobalBounds())){
		return true;
	}
	
	return false;
}