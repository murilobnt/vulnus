#ifndef _TILE_H_
#define _TILE_H_

#include <SFML/Graphics.hpp>

class Tile{
private:
  sf::Vector2f pos;
  sf::FloatRect tileRect;

public:
  Tile(sf::Vector2f pos);
  sf::Vector2f getPosition();
  float getPositionX();
  float getPositionY();
  sf::FloatRect getTileRect();
};

#endif
