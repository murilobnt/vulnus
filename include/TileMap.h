#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <SFML/Graphics.hpp>
#include "TileSet.h"

class TileMap : public sf::Drawable, public sf::Transformable {
private:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
   sf::VertexArray m_vertices;
   sf::Texture m_tileset;
   TileSet tiles;
   unsigned int levelWidth;
   unsigned int levelHeight;

public:
  bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, const int* selected, int length);
  TileSet getTiles();
  sf::Vector2u getLevelSize();
};

#endif
