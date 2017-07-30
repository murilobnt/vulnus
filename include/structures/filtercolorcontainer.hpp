#ifndef _FILTERCOLORCONTAINER_HPP_
#define _FILTERCOLORCONTAINER_HPP_

#include "generics/colorcontainer.hpp"

#define INCREASERFILTER 15

class FilterColorContainer : public ColorContainer {
private:
	bool transitionFromMorningToAfternoon();
	bool transitionFromAfternoonToEvening();
	bool transitionFromEveningToNight();
	bool transitionFromNightToMorning();


public:
	FilterColorContainer(sf::Sprite* sprite);
};

#endif