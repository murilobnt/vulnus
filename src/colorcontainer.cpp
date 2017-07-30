#include "generics/colorcontainer.hpp"

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
			if(transitionFromNightToMorning()){
				inTransition = false;
				transitionTime = GenericTimeHandler(sf::seconds(SECONDS));
			} else {
				sprite->setColor(raw);
			}
		break;
		case AFTERNOON:
			if(transitionFromMorningToAfternoon()){
				inTransition = false;
				transitionTime = GenericTimeHandler(sf::seconds(SECONDS));
			} else {
				sprite->setColor(raw);
			}
		break;
		case EVENING:
			if(transitionFromAfternoonToEvening()){
				inTransition = false;
				transitionTime = GenericTimeHandler(sf::seconds(SECONDS));
			} else {
				sprite->setColor(raw);
			}
		break;
		case NIGHT:
			if(transitionFromEveningToNight()){
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