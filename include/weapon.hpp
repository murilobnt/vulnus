#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <SFML/Graphics.hpp>

#include "weapontypes.hpp"
#include "aliveentity.hpp"
#include "enemy.hpp"
#include "tilegrid.hpp"

class Weapon{
private:
	float damage;
	bool active;
	WeaponTypes weaponType;

public:

	Weapon(float damage, WeaponTypes weaponType);
	virtual void use(AliveEntity& player) = 0;
	virtual void update() = 0;
	virtual bool isCollidingWithEnemy(const AliveEntity& enemy) = 0;
	virtual bool isCollidingWithEnvironment(const TileGrid& grid) = 0;
	virtual void draw(sf::RenderTarget& target) = 0;

	float getDamage() const;
	bool isActive() const;
	WeaponTypes getWeaponType() const;
};

#endif