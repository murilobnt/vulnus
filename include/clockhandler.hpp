#ifndef _CLOCKHANDLER_HPP_
#define _CLOCKHANDLER_HPP_

#include "generictimehandler.hpp"
#include "timehandlers.hpp"

class ClockHandler{
	private:
	sf::Clock clock;
	sf::Time elapsedTime;

	// Why don't I make all those Generic Time Handlers pointers to handlers in their related classes?
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
	void restartComboTimeHandlers(GenericTimeHandler* entityComboDelimeter);

	GenericTimeHandler* getHandler(TimeHandlers id);
};

#endif