#ifndef _BULLETSET_HPP_
#define _BULLETSET_HPP_

// # External
#include <SFML/Graphics.hpp>
#include <vector>

// # Internal
#include "bullet.hpp"

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
  std::vector<Bullet> getBulletSet() const;
};

#endif
