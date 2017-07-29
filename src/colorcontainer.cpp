#include "structures/colorcontainer.hpp"

bool ColorContainer::transitionFromBlueToYellow(){
	if(raw.a < 25){
		if(raw.a + INCREASER * 10 > 25)
			raw.a = 25;
		else
			raw.a = raw.a + INCREASER * 10;
	}

	if((int)raw.g < 255){
		if(raw.g + INCREASER * 10 > 255)
			raw.g = 255;
		else
			raw.g = raw.g + INCREASER * 10;

		return false;
	}

	if((int)raw.b > 0){
		if(raw.b - INCREASER * 10 < 0)
			raw.b = 0;
		else
			raw.b = raw.b - INCREASER * 10;

		return false;
	}

	if((int)raw.r < 255){
		if(raw.r + INCREASER * 10 > 255)
			raw.r = 255;
		else
			raw.r = raw.r + INCREASER * 10;
		return false;
	}

	return true;
}

bool ColorContainer::transitionFromYellowToOrange(){
	if(raw.a < 50){
		if(raw.a + INCREASER > 50)
			raw.a = 50;
		else
			raw.a = raw.a + INCREASER;
	}

	if((int)raw.g > 128){
		if(raw.g - INCREASER < 128)
			raw.g = 128;
		else
			raw.g = raw.g - INCREASER;

		return false;
	}

	return true;
}

bool ColorContainer::transitionFromOrangeToBlack(){
	bool r = false;
	bool g = false;
	bool a = false;

	if(raw.a < 150){
		if(raw.a + INCREASER > 150)
			raw.a = 150;
		else
			raw.a = raw.a + INCREASER;
	} else {
		a = true;
	}

	if((int)raw.r > 0){
		if(raw.r - INCREASER * 6 < 0)
			raw.r = 0;
		else
			raw.r = raw.r - INCREASER * 6;
	} else{
		r = true;
	}

	if((int)raw.g > 0){
		if(raw.g - (INCREASER * 3) < 0)
			raw.g = 0;
		else
			raw.g = raw.g - (INCREASER * 3);		
	} else{
		g = true;
	}

	if(a && r && g){
		return true;
	}
	return false;
}

bool ColorContainer::transitionFromBlackToBlue(){
	if(raw.a > 15){
		if(raw.a - INCREASER < 15)
			raw.a = 15;
		else
			raw.a = raw.a - INCREASER;
	}

	if((int)raw.b < 255){
		if(raw.b + INCREASER > 255)
			raw.b = 255;
		else
			raw.b = raw.b + INCREASER;

		return false;
	}

	return true;
}

ColorContainer::ColorContainer(sf::Sprite* sprite) : transitionTime(sf::seconds(SECONDS)){
	this->sprite = sprite;
	this->inTransition = false;
}

sf::Color ColorContainer::getRaw(){
	return this->raw;
}

GenericTimeHandler& ColorContainer::getTransitionTime(){
	return this->transitionTime;
}

void ColorContainer::setTransitionTo(DayTime period){
	this->current = period;

	this->raw = sprite->getColor();
	this->inTransition = true;
}

void ColorContainer::updateTransition(){
	if(!inTransition)
		return;

	switch(current){
		case MORNING:
			if(transitionFromBlackToBlue()){
				inTransition = false;
				transitionTime = GenericTimeHandler(sf::seconds(SECONDS));
			} else {
				sprite->setColor(raw);
			}
		break;
		case AFTERNOON:
			if(transitionFromBlueToYellow()){
				inTransition = false;
				transitionTime = GenericTimeHandler(sf::seconds(SECONDS));
			} else {
				sprite->setColor(raw);
			}
		break;
		case EVENING:
			if(transitionFromYellowToOrange()){
				inTransition = false;
				transitionTime = GenericTimeHandler(sf::seconds(SECONDS));
			} else {
				sprite->setColor(raw);
			}
		break;
		case NIGHT:
			if(transitionFromOrangeToBlack()){
				inTransition = false;
				transitionTime = GenericTimeHandler(sf::seconds(SECONDS));
			} else {
				sprite->setColor(raw);
			}
		break;
	}
}

void ColorContainer::applyColorToSprite(){
	sprite->setColor(this->raw);
}

GenericTimeHandler& ColorContainer::getTimeHandler(){
	return this->transitionTime;
}

bool ColorContainer::isInTransition(){
	return this->inTransition;
}