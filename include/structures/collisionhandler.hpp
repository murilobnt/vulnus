#ifndef _COLLISIONHANDLER_HPP_
#define _COLLISIONHANDLER_HPP_

#include <vector>

#include "entities/gamecomponents/player.hpp"
#include "entities/gamecomponents/enemy.hpp"
#include "structures/dynamicgrid.hpp"
#include "structures/collision.h"
#include "structures/bullet.hpp"

class CollisionHandler{
private:
	DynamicGrid dynaGrid;

public:
	CollisionHandler(DynamicGrid dynaGrid);
	CollisionHandler();
	bool collisionBetweenPAndE(const Player& player, const Enemy& enemy) const;
	bool collisionBetweenBAndE(const Bullet& bullet, const Enemy& enemy) const;
};

#endif