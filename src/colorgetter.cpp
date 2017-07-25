#include "structures/colorgetter.hpp"

sf::Color ColorGetter::GetScreenFilterColorToDayTime(DayTime Period){
	switch(Period){
		case MORNING:
			return sf::Color(0.f, 0.f, 255.f, 15.f);
		break;
		case AFTERNOON:
			return sf::Color(255.f, 255.f, 0.f, 25.f);
		break;
		case EVENING:
			return sf::Color(255.f, 128.f, 0.f, 50.f);
		break;
		case NIGHT:
			return sf::Color(0.f, 0.f, 0.f, 150.f);
		break;
		default:
			return sf::Color(0.f, 0.f, 255.f, 50.f);
		break;
	}
}

sf::Color ColorGetter::GetBackgroundFilterColorToDayTime(DayTime Period){
	switch(Period){
		case MORNING:
			return sf::Color(255.f, 255.f, 255.f, 200.f);
		break;
		case AFTERNOON:
			return sf::Color(255.f, 255.f, 255.f, 255.f);
		break;
		case EVENING:
			return sf::Color(255.f, 255.f, 255.f, 150.f);
		break;
		case NIGHT:
			return sf::Color(255.f, 255.f, 255.f, 40.f);
		break;
		default:
			return sf::Color(255.f, 255.f, 255.f, 15.f);
		break;
	}
}