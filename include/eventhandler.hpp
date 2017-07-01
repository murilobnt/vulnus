#ifndef _EVENTHANDLER_HPP_
#define _EVENTHANDLER_HPP_

// # External
#include <SFML/Graphics.hpp>

// # Internal
#include "player.hpp"
#include "cutscene.hpp"
#include "inputhandler.hpp"

class EventHandler {
private:
	InputHandler inputhandler;

	Player* player;
	Cutscene* cutscene;
public:
	EventHandler(Player* player, Cutscene* cutscene);
	InputHandler getInputHandler() const;
	bool handleEvent(sf::Event event);
	void handleMouseEvent(sf::Event event, sf::RenderWindow& screen);
};

#endif