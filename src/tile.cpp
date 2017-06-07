#include "tile.hpp"

Tile::Tile(sf::Vector2f tilePosition, int id){
  this->tilePosition = tilePosition;
  this->id = id;
  tileRect = sf::FloatRect(tilePosition, sf::Vector2f(32, 32));
}

sf::Vector2f Tile::getPosition() const{
  return this->tilePosition;
}

float Tile::getPositionX() const{
  return this->tilePosition.x;
}

float Tile::getPositionY() const{
  return this->tilePosition.y;
}

sf::FloatRect Tile::getTileRect() const{
  return this->tileRect;
}
