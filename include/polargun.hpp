#ifndef _POLARGUN_HPP_
#define _POLARGUN_HPP_

#include <vector>
#include <SFML/Graphics.hpp>

#include "bullet.hpp"
#include "weapon.hpp"

class PolarGun : public Weapon {
private:
	std::vector<Bullet> bullets;

public:
	PolarGun(float damage);
	void use(Player& player);
	void update();
	bool isCollindingWithEnemy(const Enemy& enemy);
};

#endif