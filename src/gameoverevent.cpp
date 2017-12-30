#include "structures/gameoverevent.hpp"

GameOverEvent::GameOverEvent(int yRule, Player& player) : player(player){
	this->yRule = yRule;
}

bool GameOverEvent::isConditionSatisfied(){
	if(player.getSpritePosition().y > yRule)
		return true;

	return false;
}