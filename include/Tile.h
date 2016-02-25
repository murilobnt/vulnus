#ifndef _TILE_H_
#define _TILE_H_

#include <SFML/Graphics.hpp>

class Tile{
private:
  // The position of the tile
  sf::Vector2f pos;

  // The rect of the tile
  sf::FloatRect tileRect;

public:
  /**
   * Constructor.
   * @param pos the position of the tile
   */
  Tile(sf::Vector2f pos);

  /**
   * Get the position of the tile.
   * @return the position of the tile
   */
  sf::Vector2f getPosition();

  /**
   * Get the position in x axis.
   * @return the position in x axis
   */
  float getPositionX();

  /**
   * Get the position in y axis.
   * @return the position in y axis
   */
  float getPositionY();

  /**
   * Get the tile rect.
   * @return the tile rect
   */
  sf::FloatRect getTileRect();
};

#endif
