#ifndef _BULLETSET_H_
#define _BULLETSET_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

class BulletSet{
private:
  // The set of the bullets
  std::vector<Bullet> bulletSet;
public:
  /**
   * Constructor.
   */
  BulletSet();

  /**
   * Add a bullet to the set.
   * @param bullet the bullet to be added on the set
   */
  void addBullet(Bullet bullet);

  /**
   * Check if has at least one bullet in the set.
   * @return if has at least one bullet in the set
   */
  bool hasAtLeastOneBullet();

  /**
   * Get the set of the bullets.
   * @return the set of the bullets.
   */
  std::vector<Bullet> getBulletSet();
};

#endif
