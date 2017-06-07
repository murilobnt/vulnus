#ifndef _COLLISIONHANDLER_HPP_
#define _COLLISIONHANDLER_HPP_

#include <vector>
#include <iostream>

#include "player.hpp"
#include "enemy.hpp"
#include "dynamicgrid.hpp"
#include "collision.h"
#include "bullet.hpp"

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