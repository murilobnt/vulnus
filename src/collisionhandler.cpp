#include "collisionhandler.hpp"

CollisionHandler::CollisionHandler(DynamicGrid dynaGrid){
	this->dynaGrid = dynaGrid;
}

CollisionHandler::CollisionHandler(){
	
}

bool CollisionHandler::collisionBetweenPAndE(Player player, Enemy enemy){
	if(player.getQuad() == enemy.getQuad()){
		if(enemy.getSprite().getGlobalBounds().intersects(player.getSprite().getGlobalBounds()) && !player.getInvulnerability()){
			//player->receiveDamage(enemy.getDamage());
			// This was supposed to be a sound from PLAYER, not from a general sound table.
			//soundTable.playSound(3);
			return true;
		}
	}
	return false;
}