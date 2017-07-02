#ifndef _SPRITEDENTITY_HPP_
#define _SPRITEDENTITY_HPP_

#include <SFML/Graphics.hpp>

class SpritedEntity {
private:
	sf::Sprite sprite;

	int spriteInitX;
	int spriteEndX;
	int spriteInitY;
	int spriteEndY;
public:
	SpritedEntity(sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY);

	void configureSpriteRect(int x, int y, int w, int h);
	void setSpritePosition(sf::Vector2f position);
	void setSpritePosition(float x, float y);
	void moveSprite(sf::Vector2f movement);
	void setSpriteColor(sf::Color color);

	sf::Sprite getSprite() const;
	sf::Vector2f getSpritePosition() const;
	sf::FloatRect getSpriteGlobalBounds() const;
	sf::FloatRect getSpriteLocalBounds() const;

	int getSpriteInitX() const;
	int getSpriteEndX() const;
	int getSpriteInitY() const;
	int getSpriteEndY() const;
};

#endif