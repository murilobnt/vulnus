#ifndef _PLAYERMOUSECONTROL_HPP_
#define _PLAYERMOUSECONTROL_HPP_

#include "generics/mousecontrol.hpp"

class PlayerMouseControl : public MouseControl {
public:
	void controlEntityByMouse(sf::Event event, SpritedEntity& spritedEntity, sf::Vector2f mousePos);
};

#endif