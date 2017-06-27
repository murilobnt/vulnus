#include "clockhandler.hpp"

ClockHandler::ClockHandler(){

}

void ClockHandler::restartClock(){
	this->elapsedTime = this->clock.restart();
}

void ClockHandler::restartTimeHandler(GenericTimeHandler* entityComboDelimeter){
	entityComboDelimeter->restart(this->elapsedTime);
}