#include "tilemap.hpp"

TileMap::TileMap() : tiles(0, 0, 0){ }

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, const int* selected, int length) {
  this->levelWidth = width * 32;
  this->levelHeight = height * 32;

  this->tiles = TileSet(levelWidth, levelHeight, 150);

  // load the tileset texture
  if (!m_tileset.loadFromFile(tileset))
      return false;

  // resize the vertex array to fit the level size
  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(width * height * 4);

  int p = 0;

  // populate the vertex array, with one quad per tile
  for (unsigned int i = 0; i < width; ++i)
      for (unsigned int j = 0; j < height; ++j) {
          // get the current tile number
          int tileNumber = tiles[i + j * width];

          // find its position in the tileset texture
          int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
          int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

          if(tu != 0){
            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            for(int k = 0; k < length; k++){
              if(tu == selected[k]){
                this->tiles.addTile(Tile(quad[0].position, p++));
                //break;
              }
            }

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
          }
      }
  return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();
    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}

TileSet TileMap::getTiles(){
  return this->tiles;
}

sf::Vector2u TileMap::getLevelSize(){
  return sf::Vector2u(this->levelWidth, this->levelHeight);
}
