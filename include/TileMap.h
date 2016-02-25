#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <SFML/Graphics.hpp>
#include "TileSet.h"

class TileMap : public sf::Drawable, public sf::Transformable {
private:
  /**
   * Draw all tiles.
   * @param target the window to draw the tiles
   * @param states the state of the window
   */
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

   // The vertices of the tiles
   sf::VertexArray m_vertices;

   // The texture of the tiles
   sf::Texture m_tileset;

   // The set of the tiles
   TileSet tiles;

   // The width of the level
   unsigned int levelWidth;

   // The height of the level
   unsigned int levelHeight;

public:
  /**
   * Load the tileset.
   * @param tileset the path to tiles' texture
   * @param tileSize the size of every tile
   * @param tiles the level represented on array
   * @param width the width of the level array
   * @param height the height of the level array
   * @param selected the selected tiles to be collided
   * @param lenght the lenght of selected array
   */
  bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, const int* selected, int length);

  /**
   * Get the all the colliding tiles.
   * @return all the colliding tiles
   */
  TileSet getTiles();

  /**
   * Get the size of the level.
   * @return the size of the level
   */
  sf::Vector2u getLevelSize();
};

#endif
