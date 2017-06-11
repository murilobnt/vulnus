#ifndef _POLARGUN_HPP_
#define _POLARGUN_HPP_

#include <vector>

#include "bullet.hpp"
#include "weapon.hpp"

class PolarGun : public Weapon {
private:
	std::vector<Bullet> bullets;

public:
	PolarGun(float damage);
	void use(AliveEntity& player);
	void update();
	bool isCollidingWithEnemy(const AliveEntity& enemy);
	bool isCollidingWithEnvironment(const TileGrid& grid);
	void draw(sf::RenderTarget& target);
};

#endif