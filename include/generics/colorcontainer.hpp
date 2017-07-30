#ifndef _COLORCONTAINER_HPP_
#define _COLORCONTAINER_HPP_

#include <SFML/Graphics.hpp>

#include "entities/clock/generictimehandler.hpp"
#include "enums/daytime.hpp"

#define SECONDS 0.3f

class ColorContainer{
private:
	virtual bool transitionFromMorningToAfternoon() = 0;
	virtual bool transitionFromAfternoonToEvening() = 0;
	virtual bool transitionFromEveningToNight() = 0;
	virtual bool transitionFromNightToMorning() = 0;

	GenericTimeHandler transitionTime;

	sf::Sprite* sprite;
	bool inTransition;
	DayTime current;

protected:
	sf::Color raw;

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