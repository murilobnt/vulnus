#include "collisionhandler.hpp"

CollisionHandler::CollisionHandler(DynamicGrid dynaGrid){
	this->dynaGrid = dynaGrid;
}

CollisionHandler::CollisionHandler(){
	
}

bool CollisionHandler::collisionBetweenPAndE(Player player, Enemy enemy){
	if(player.getQuad() == enemy.getQuad()){
		if(Collision::PixelPerfectTest(player.getSprite(), enemy.getSprite()) && !player.getInvulnerability()){
			return true;
		}
	}
	return false;
}