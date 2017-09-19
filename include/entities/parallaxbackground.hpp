#ifndef _PARALLAXBACKGROUND_HPP_
#define _PARALLAXBACKGROUND_HPP_

#include <SFML/Graphics.hpp>

class ParallaxBackground {
private:
	int levelW;
	int levelH;

	sf::Sprite bg;

	double movementFactor;

public:
	ParallaxBackground(sf::Texture& texture, double movementFactor);
	double getMovementFactor();
	sf::Sprite* getSpriteRef();
	sf::Sprite& getSprite();

	void initLevelWandH(int levelW, int levelH);
	void setLevelW(int levelW);
	void setLevelH(int levelH);
};

#endif