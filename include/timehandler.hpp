#ifndef _TIMEHANDLER_HPP_
#define _TIMEHANDLER_HPP_

// # External
#include <SFML/Graphics.hpp>

class TimeHandler{
private:
	sf::Clock clock;

	sf::Time gameLastUpdate;
	sf::Time gameFps;

	sf::Time playerAnimLastUpdate;
	sf::Time playerAnimFps;

	sf::Time playerSoundLastUpdate;
	sf::Time playerSoundFps;

	sf::Time playerInvulnLastUpdate;
	sf::Time playerInvulnTime;

	sf::Time playerInvulnAnimLastUpdate;
	sf::Time playerInvulnAnimFps;

	sf::Time elapsedTime;

public:
	TimeHandler();

	bool timeToUpdateGame();
	bool timeToUpdatePlayerAnimation();
	bool timeToUpdatePlayerSound();
	
	bool timeToEndPlayerInvulnerability();
	bool timeToBlinkPlayer();

	void restartClock();
	void restartTime();
	void restartInvulnTime();
};

#endif