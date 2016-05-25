#include "Bullet.h"

Bullet::Bullet(float speed, sf::Vector2f playerPos, bool movingRight) : bulletSprite(sf::Vector2f(20, 5)){
  this->markedForDeath = false;
  this->initialPosition = playerPos;
  this->movingRight = movingRight;
  this->speed = speed;
  this->bulletSprite.setPosition(playerPos);
  bulletSprite.setFillColor(sf::Color::Red);
}

void Bullet::moveBullet(){
  this->movingRight ? bulletSprite.move(sf::Vector2f(speed, 0)) : bulletSprite.move(sf::Vector2f(-speed, 0));
}

sf::Vector2f Bullet::getBulletPosition(){
  return this->bulletSprite.getPosition();
}

sf::RectangleShape Bullet::getBullet(){
  return this->bulletSprite;
}

void Bullet::shouldBeDestroyed(bool markedForDeath){
  if(markedForDeath){
    this->markedForDeath = true;
    return;
  }
  if(movingRight){
    if(this->bulletSprite.getPosition().x > this->initialPosition.x + 200){
      this->markedForDeath = true;
    }
  } else {
    if(this->bulletSprite.getPosition().x < this->initialPosition.x - 200){
      this->markedForDeath = true;
    }
  }
}

bool Bullet::getMarkedForDeath(){
  return this->markedForDeath;
}
