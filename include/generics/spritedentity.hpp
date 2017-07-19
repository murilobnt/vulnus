#ifndef _SPRITEDENTITY_HPP_
#define _SPRITEDENTITY_HPP_

#include <SFML/Graphics.hpp>

class SpritedEntity {
private:
	sf::Sprite sprite;

public:
	SpritedEntity(sf::Texture const& texture, int spriteX, int spriteY, int spriteW = 32, int spriteH = 32);

	void configureSpriteRect(int x, int y, int w, int h);
	void setSpritePosition(sf::Vector2f position);
	void setSpritePosition(float x, float y);
	void moveSprite(sf::Vector2f movement);
	void setSpriteColor(sf::Color color);

	sf::Sprite getSprite() const;
	sf::Vector2f getSpritePosition() const;
	sf::FloatRect getSpriteGlobalBounds() const;
	sf::FloatRect getSpriteLocalBounds() const;
};

#endif