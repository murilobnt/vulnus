#ifndef _EVENTHANDLER_HPP_
#define _EVENTHANDLER_HPP_

// # External
#include <SFML/Graphics.hpp>

// # Internal
#include "generics/controlableentity.hpp"

class EventHandler {
public:
	void handleEvent(sf::Event event, ControlableEntity& entity);
};

#endif