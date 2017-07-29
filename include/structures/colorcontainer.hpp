#ifndef _COLORCONTAINER_HPP_
#define _COLORCONTAINER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "entities/clock/generictimehandler.hpp"
#include "enums/daytime.hpp"

#define SECONDS 0.3f
#define INCREASER 5

class ColorContainer{
private:
	bool transitionFromBlueToYellow();
	bool transitionFromYellowToOrange();
	bool transitionFromOrangeToBlack();
	bool transitionFromBlackToBlue();

	sf::Color raw;
	GenericTimeHandler transitionTime;

	sf::Sprite* sprite;
	bool inTransition;
	DayTime current;

public:
	ColorContainer(sf::Sprite* sprite);

	sf::Color getRaw();

	GenericTimeHandler& getTransitionTime();

	void setTransitionTo(DayTime Period);
	void updateTransition();

	void applyColorToSprite();
	GenericTimeHandler& getTimeHandler();
	bool isInTransition();
};

#endif