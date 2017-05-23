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

	sf::Time elapsedTime;

public:
	TimeHandler();

	bool timeToUpdateGame();
	bool timeToUpdatePlayerAnimation();
	bool timeToUpdatePlayerSound();

	void restartTime();
};

#endif