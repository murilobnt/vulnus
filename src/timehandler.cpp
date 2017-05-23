#include "timehandler.hpp"

TimeHandler::TimeHandler(){
	this->gameFps = sf::seconds(1.f / 60.f);
	this->playerAnimFps = sf::seconds(1.f / 10.f);
	this->playerSoundFps = sf::seconds(1.f / 5.f);

	this->gameLastUpdate = sf::Time::Zero;
	this->playerAnimLastUpdate = sf::Time::Zero;
	this->playerSoundLastUpdate = sf::Time::Zero;
}

bool TimeHandler::timeToUpdateGame(){
	if(this->gameLastUpdate > this->gameFps){
		this->gameLastUpdate -= this->gameFps;
		return true;
	}
	return false;
}

bool TimeHandler::timeToUpdatePlayerAnimation(){
	if(this->playerAnimLastUpdate > this->playerAnimFps){
		this->playerAnimLastUpdate -= this->playerAnimFps;
		return true;
	}
	return false;
}

bool TimeHandler::timeToUpdatePlayerSound(){
	if(this->playerSoundLastUpdate > this->playerSoundFps){
		this->playerSoundLastUpdate -= this->playerSoundFps;
		return true;
	}
	return false;
}

void TimeHandler::restartTime(){
	this->elapsedTime = this->clock.restart();

	this->gameLastUpdate += elapsedTime;
	this->playerAnimLastUpdate += elapsedTime;
	this->playerSoundLastUpdate += elapsedTime;
}