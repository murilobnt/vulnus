#include "Tile.h"

Tile::Tile(sf::Vector2f tilePosition, int id){
  this->tilePosition = tilePosition;
  this->id = id;
  tileRect = sf::FloatRect(tilePosition, sf::Vector2f(32, 32));
}

sf::Vector2f Tile::getPosition(){
  return this->tilePosition;
}

float Tile::getPositionX(){
  return this->tilePosition.x;
}

float Tile::getPositionY(){
  return this->tilePosition.y;
}

sf::FloatRect Tile::getTileRect(){
  return this->tileRect;
}
