#ifndef _GAMEOVEREVENT_HPP_
#define _GAMEOVEREVENT_HPP_

#include <SFML/Graphics.hpp>

#include "generics/event.hpp"
#include "entities/gamecomponents/player.hpp"

class GameOverEvent : public Event {
private:
	int yRule;
	Player& player;

public:
	GameOverEvent(int yRule, Player& player);
	bool isConditionSatisfied();
};

#endif