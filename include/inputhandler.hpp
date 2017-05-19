#ifndef _INPUTHANDLER_HPP_
#define _INPUTHANDLER_HPP_

// # External
#include <SFML/Graphics.hpp>

// # Internal
#include "player.hpp"

class InputHandler {
public:
	void handlePlayerInput(Player* player, sf::Keyboard::Key key, bool release);
	void handleMouseInput(Player* player, sf::Vector2f mousePosition);
};

#endif