#include "structures/weekcontainer.hpp"

WeekContainer::WeekContainer(){
	this->dofw = MON;
	this->currentDofw = MON;
}

WeekContainer::WeekContainer(DayOfTheWeek dofw){
	this->dofw = dofw;
	this->currentDofw = dofw;
}

void WeekContainer::incrementDofw(){
	currentDofw++;
	if(currentDofw > 6)
		currentDofw = 0;
	dofw = static_cast<DayOfTheWeek>(currentDofw);
}

void WeekContainer::setDofw(DayOfTheWeek dofw){
	this->dofw = dofw;
	this->currentDofw = dofw;
}

DayOfTheWeek WeekContainer::getDofw(){
	return dofw;
}

std::string WeekContainer::getDofwText(){
	switch(dofw){
		case SAT:
			return "SAT";
		break;
		case SUN:
			return "SUN";
		break;
		case MON:
			return "MON";
		break;
		case TUE:
			return "TUE";
		break;
		case WED:
			return "WED";
		break;
		case THU:
			return "THU";
		break;
		case FRI:
			return "FRI";
		break;
		default:
			return "LOL";
		break;
	}
}