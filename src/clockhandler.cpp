#include "clockhandler.hpp"

ClockHandler::ClockHandler(GenericTimeHandler* entityComboDelimeter) :
gameFrequency(sf::seconds(1.f / 60.f)),
playerAnimation(sf::seconds(1.f / 10.f)),
playerSound(sf::seconds(1.f / 5.f)),
playerInvulnerability(sf::seconds(2)),
playerInvulnerabilityAnimation(sf::seconds(1.f / 15.f)) {
	this->entityComboDelimeter = entityComboDelimeter;
}

void ClockHandler::restartClock(){
	this->elapsedTime = this->clock.restart();
}

void ClockHandler::restartTimeHandlers(){
	gameFrequency.restart(this->elapsedTime);
	playerAnimation.restart(this->elapsedTime);
	playerSound.restart(this->elapsedTime);
}

void ClockHandler::restartInvulnTimeHandlers(){
	playerInvulnerability.restart(this->elapsedTime);
	playerInvulnerabilityAnimation.restart(this->elapsedTime);
}

void ClockHandler::restartComboTimeHandlers(){
	entityComboDelimeter->restart(this->elapsedTime);
}

GenericTimeHandler* ClockHandler::getHandler(TimeHandlers id){
	switch(id){
		case GAMEFREQ:
		return &gameFrequency;
		break;
		case PLAYERANIM:
		return &playerAnimation;
		break;
		case PLAYERSOUND:
		return &playerSound;
		break;
		case PLAYERINVULN:
		return &playerInvulnerability;
		break;
		case PLAYERINVULNANIM:
		return &playerInvulnerabilityAnimation;
		break;
		case ENTITYCOMBO:
		return entityComboDelimeter;
		break;
		default:
		return &gameFrequency;
		break;
	}
}