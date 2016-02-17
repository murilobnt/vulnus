#ifndef _BULLET_H_
#define _BULLET_H_

#include <SFML/Graphics.hpp>

class Bullet{
private:
  float speed;
  bool movingRight;
  sf::RectangleShape bullet;
  sf::Vector2f initialPosition;
  bool markedForDeath;

public:
  Bullet(float speed, sf::Vector2f playerPos, bool movingRight);
  void moveBullet();
  sf::Vector2f getBulletPosition();
  sf::RectangleShape getBullet();
  void shouldBeDestroyed(bool markedForDeath);
  bool getMarkedForDeath();
};

#endif
