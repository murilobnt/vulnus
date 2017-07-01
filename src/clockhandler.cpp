#include "clockhandler.hpp"

ClockHandler::ClockHandler(){

}

void ClockHandler::restartClock(){
	this->elapsedTime = this->clock.restart();
}

void ClockHandler::restartTimeHandler(GenericTimeHandler* genericTimeHandler){
	genericTimeHandler->restart(this->elapsedTime);
}