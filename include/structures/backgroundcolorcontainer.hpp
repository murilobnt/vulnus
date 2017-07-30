#ifndef _BACKGROUNDCOLORCONTAINER_HPP_
#define _BACKGROUNDCOLORCONTAINER_HPP_

#include "generics/colorcontainer.hpp"

#define INCREASER 5

class BackgroundColorContainer : public ColorContainer {
private:
	bool transitionFromMorningToAfternoon();
	bool transitionFromAfternoonToEvening();
	bool transitionFromEveningToNight();
	bool transitionFromNightToMorning();

public:
	BackgroundColorContainer(sf::Sprite* sprite);
};

#endif