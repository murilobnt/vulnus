#include "structures/filtercolorcontainer.hpp"

FilterColorContainer::FilterColorContainer(sf::Sprite* sprite)
: ColorContainer::ColorContainer(sprite){

}

bool FilterColorContainer::transitionFromMorningToAfternoon(){
	if(raw.a < 25){
		if(raw.a + INCREASERFILTER * 3 > 25)
			raw.a = 25;
		else
			raw.a = raw.a + INCREASERFILTER * 3;
	}

	if((int)raw.g < 255){
		if(raw.g + INCREASERFILTER * 3 > 255)
			raw.g = 255;
		else
			raw.g = raw.g + INCREASERFILTER * 3;

		return false;
	}

	if((int)raw.b > 0){
		if(raw.b - INCREASERFILTER * 3 < 0)
			raw.b = 0;
		else
			raw.b = raw.b - INCREASERFILTER * 3;

		return false;
	}

	if((int)raw.r < 255){
		if(raw.r + INCREASERFILTER * 3 > 255)
			raw.r = 255;
		else
			raw.r = raw.r + INCREASERFILTER * 3;
		return false;
	}

	if(raw.a < 25)
		return false;

	return true;
}

bool FilterColorContainer::transitionFromAfternoonToEvening(){
	if(raw.a < 50){
		if(raw.a + INCREASERFILTER/2 > 50)
			raw.a = 50;
		else
			raw.a = raw.a + INCREASERFILTER/2;
	}

	if((int)raw.g > 128){
		if(raw.g - INCREASERFILTER/2 < 128)
			raw.g = 128;
		else
			raw.g = raw.g - INCREASERFILTER/2;

		return false;
	}

	if(raw.a < 50)
		return false;

	return true;
}

bool FilterColorContainer::transitionFromEveningToNight(){
	bool r = false;
	bool g = false;
	bool a = false;

	if(raw.a < 150){
		if(raw.a + INCREASERFILTER/3 > 150)
			raw.a = 150;
		else
			raw.a = raw.a + INCREASERFILTER/3;
	} else {
		a = true;
	}

	if((int)raw.r > 0){
		if(raw.r - INCREASERFILTER * 1.5 < 0)
			raw.r = 0;
		else
			raw.r = raw.r - INCREASERFILTER * 1.5;
	} else{
		r = true;
	}

	if((int)raw.g > 0){
		if(raw.g - (INCREASERFILTER * 1.5) < 0)
			raw.g = 0;
		else
			raw.g = raw.g - (INCREASERFILTER * 1.5);		
	} else{
		g = true;
	}

	if(a && r && g){
		return true;
	}
	return false;
}

bool FilterColorContainer::transitionFromNightToMorning(){
	if(raw.a > 15){
		if(raw.a - INCREASERFILTER < 15)
			raw.a = 15;
		else
			raw.a = raw.a - INCREASERFILTER;
	}

	if((int)raw.b < 255){
		if(raw.b + INCREASERFILTER > 255)
			raw.b = 255;
		else
			raw.b = raw.b + INCREASERFILTER;

		return false;
	}

	if(raw.a > 15)
		return false;

	return true;
}