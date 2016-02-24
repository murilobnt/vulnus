#ifndef _BULLET_H_
#define _BULLET_H_

#include <SFML/Graphics.hpp>

class Bullet{
private:
  // Speed of the bullet
  float speed;
  // Verifier to tell if the bullet is moving right or not
  bool movingRight;
  // The rectangle of the bullet to be drawn
  sf::RectangleShape bullet;
  // The initial position of the bullet
  sf::Vector2f initialPosition;
  // Verifier to tell if the bullet may be destroyed on the next verification
  bool markedForDeath;

public:
  /**
	 * Constructor.
   * @param speed the speed of the bullet
   * @param playerPos the position of the player
   * @param movingRight the orientation of the bullet
	 */
  Bullet(float speed, sf::Vector2f playerPos, bool movingRight);
  /**
   * Move the bullet.
   */
  void moveBullet();

  /**
   * Get the position of the bullet.
   * @return the bullet position
   */
  sf::Vector2f getBulletPosition();

  /**
   * Get the bullet sprite.
   * @return the bullet sprite
   */
  sf::RectangleShape getBullet();

  /**
   * Verify if the bullet should be destroyed. If so, he destroys the bullet.
   * @param markedForDeath should be true if you want to update to destroy it next verification
   */
  void shouldBeDestroyed(bool markedForDeath);

  /**
   * Get if the bullet is marked to be destroyed or not.
   */
  bool getMarkedForDeath();
};

#endif
