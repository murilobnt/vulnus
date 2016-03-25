#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy : public AliveEntity{

public:
  Enemy(int x, int y, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity);
};

#endif
