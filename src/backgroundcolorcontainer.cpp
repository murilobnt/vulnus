#include "structures/backgroundcolorcontainer.hpp"

BackgroundColorContainer::BackgroundColorContainer(sf::Sprite* sprite)
: ColorContainer::ColorContainer(sprite){

}

bool BackgroundColorContainer::transitionFromMorningToAfternoon(){
	if(raw.a < 255){
		if(raw.a + INCREASER > 255)
			raw.a = 255;
		else
			raw.a = raw.a + INCREASER;

		return false;
	}

	return true;
}

bool BackgroundColorContainer::transitionFromAfternoonToEvening(){
	if(raw.a > 150){
		if(raw.a - INCREASER < 150){
			raw.a = 150;
		}
		else
			raw.a = raw.a - INCREASER;

		return false;
	}

	return true;
}

bool BackgroundColorContainer::transitionFromEveningToNight(){
	if(raw.a > 40){
		if(raw.a - INCREASER < 40)
			raw.a = 40;
		else
			raw.a = raw.a - INCREASER;

		return false;
	}

	return true;
}

bool BackgroundColorContainer::transitionFromNightToMorning(){
	if(raw.a < 200){
		if(raw.a + INCREASER > 200)
			raw.a = 200;
		else
			raw.a = raw.a + INCREASER;

		return false;
	}

	return true;
}