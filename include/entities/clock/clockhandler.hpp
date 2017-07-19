#ifndef _CLOCKHANDLER_HPP_
#define _CLOCKHANDLER_HPP_

#include "entities/clock/generictimehandler.hpp"
#include "enums/timehandlers.hpp"

class ClockHandler{
	private:
	sf::Clock clock;
	sf::Time elapsedTime;

public:
	ClockHandler();

	void restartClock();
	void restartTimeHandler(GenericTimeHandler* genericTimeHandler);
};

#endif