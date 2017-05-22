#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_

// # External
#include <SFML/Graphics.hpp>

// # Internal
#include "aliveentity.hpp"

class Enemy : public AliveEntity{

public:
  Enemy(int x, int y, float health, float speed, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY);
  void moveEnemy(sf::Vector2f playerPosition);
  void stopEnemy();
  void jump();
  bool playerIsInRadious(sf::Vector2f myPosition, sf::Vector2f playerPosition);
};

#endif
