#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "AliveEntity.h"

class Enemy : public AliveEntity{

public:
  Enemy(int x, int y, float health, float speed, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY);
};

#endif
