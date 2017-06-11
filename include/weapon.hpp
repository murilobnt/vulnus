#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include "weapontypes.hpp"
#include "player.hpp"
#include "enemy.hpp"

class Weapon{
private:
	float damage;
	bool active;
	WeaponTypes weaponType;

public:
	Weapon(float damage, WeaponTypes weaponType);
	virtual void use(Player& player) = 0;
	virtual void update() = 0;
	virtual bool isCollindingWithEnemy(const Enemy& enemy);
};

#endif