#ifndef _BLADE_HPP_
#define _BLADE_HPP_

#include <SFML/Graphics.hpp>

#include "aliveentity.hpp"
#include "weapon.hpp"

class Blade : public Weapon {
private:
	sf::RectangleShape sprite;

public:
	Blade(float damage);

	void use(AliveEntity& player);
	void update();
	bool isCollidingWithEnemy(const AliveEntity& enemy);
	bool isCollidingWithEnvironment(const TileGrid& grid);
	void draw(sf::RenderTarget& target);
};

#endif