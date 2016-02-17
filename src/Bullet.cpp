#include "Bullet.h"

Bullet::Bullet(float speed, sf::Vector2f playerPos, bool movingRight) : bullet(sf::Vector2f(20, 5)){
  this->markedForDeath = false;
  this->initialPosition = playerPos;
  this->movingRight = movingRight;
  this->speed = speed;
  this->bullet.setPosition(playerPos);
}

void Bullet::moveBullet(){
  this->movingRight ? bullet.move(sf::Vector2f(speed, 0)) : bullet.move(sf::Vector2f(-speed, 0));
}

sf::Vector2f Bullet::getBulletPosition(){
  return this->bullet.getPosition();
}

sf::RectangleShape Bullet::getBullet(){
  return this->bullet;
}

void Bullet::shouldBeDestroyed(bool markedForDeath){
  if(markedForDeath){
    this->markedForDeath = true;
    return;
  }
  if(movingRight){
    if(this->bullet.getPosition().x > this->initialPosition.x + 200){
      this->markedForDeath = true;
    }
  } else {
    if(this->bullet.getPosition().x < this->initialPosition.x - 200){
      this->markedForDeath = true;
    }
  }
}

bool Bullet::getMarkedForDeath(){
  return this->markedForDeath;
}
