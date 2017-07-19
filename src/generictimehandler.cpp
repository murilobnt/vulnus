#include "entities/clock/generictimehandler.hpp"

GenericTimeHandler::GenericTimeHandler(){
	
}

GenericTimeHandler::GenericTimeHandler(sf::Time fps){
	this->lastUpdate = sf::Time::Zero;
	this->fps = fps;
}

void GenericTimeHandler::restart(sf::Time elapsedTime){
	this->lastUpdate += elapsedTime;
}

bool GenericTimeHandler::timeToUpdate(){
	if(this->lastUpdate > this->fps){
		this->lastUpdate -= this->fps;
		return true;
	}
	return false;
}

void GenericTimeHandler::resetLastUpdate(){
	this->lastUpdate = sf::Time::Zero;
}