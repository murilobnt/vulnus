#ifndef _CLOCKHANDLER_HPP_
#define _CLOCKHANDLER_HPP_

#include "generictimehandler.hpp"
#include "timehandlers.hpp"

class ClockHandler{
	private:
	sf::Clock clock;
	sf::Time elapsedTime;

	GenericTimeHandler gameFrequency;
	GenericTimeHandler playerAnimation;
	GenericTimeHandler playerSound;
	GenericTimeHandler playerInvulnerability;
	GenericTimeHandler playerInvulnerabilityAnimation;

public:
	ClockHandler();

	void restartClock();
	void restartTimeHandlers();
	void restartInvulnTimeHandlers();

	GenericTimeHandler* getHandler(TimeHandlers id);
};

#endif