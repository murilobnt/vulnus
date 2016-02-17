#ifndef _BULLETSET_H_
#define _BULLETSET_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

class BulletSet{
private:
  std::vector<Bullet> bulletSet;
public:
  BulletSet();
  void addBullet(Bullet bullet);
  bool hasAtLeastOneBullet();
  std::vector<Bullet> getBulletSet();
};

#endif
