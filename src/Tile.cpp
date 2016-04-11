#include "Tile.h"

Tile::Tile(sf::Vector2f pos, int id){
  this->pos = pos;
  this->id = id;
  tileRect = sf::FloatRect(pos, sf::Vector2f(32, 32));
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

sf::FloatRect Tile::getTileRect(){
  return this->tileRect;
}
