#ifndef _EVENTHANDLER_HPP_
#define _EVENTHANDLER_HPP_

// # External
#include <SFML/Graphics.hpp>

// # Internal
#include "entities/gamecomponents/player.hpp"
#include "entities/cutscene/cutscene.hpp"
#include "structures/inputhandler.hpp"

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