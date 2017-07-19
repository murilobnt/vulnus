#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <SFML/Graphics.hpp>

#include "enums/weapontypes.hpp"
#include "generics/aliveentity.hpp"

#include "entities/gamecomponents/enemy.hpp"
#include "structures/tilegrid.hpp"
#include "entities/clock/clockhandler.hpp"

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
	void setDamage(const float damage);
	bool isActive() const;
	void setActive(const bool active);
	WeaponTypes getWeaponType() const;
};

#endif