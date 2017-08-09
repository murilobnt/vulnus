#ifndef _MOUSECONTROL_HPP_
#define _MOUSECONTROL_HPP_

#include <SFML/Graphics.hpp>

#include "generics/spritedentity.hpp"

class MouseControl{
public:
	virtual void controlEntityByMouse(sf::Event event, SpritedEntity& spritedEntity, sf::Vector2f mousePos) = 0;
};

#endif