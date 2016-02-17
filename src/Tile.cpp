#include "Tile.h"

Tile::Tile(sf::Vector2f pos){
  this->pos = pos;
}

sf::Vector2f Tile::getPosition(){
  return this->pos;
}

float Tile::getPositionX(){
  return this->pos.x;
}

float Tile::getPositionY(){
  return this->pos.y;
}
