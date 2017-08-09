#ifndef _CONTROLABLEENTITY_HPP_
#define _CONTROLABLEENTITY_HPP_

class ControlableEntity {
public:
	virtual void controlEntity(sf::Keyboard::Key key, bool release) = 0;
};

#endif