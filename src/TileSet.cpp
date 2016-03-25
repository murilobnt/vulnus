#include "TileSet.h"

TileSet::TileSet(){ }

void TileSet::addTile(Tile tile){
  this->tileSet.push_back(tile);
}

void TileSet::verifyPlayerCollision(Player* player){
  sf::Vector2f playerPosition = player->getSprite().getPosition();

  for(std::vector<Tile>::iterator it = this->tileSet.begin(); it != this->tileSet.end(); ++it) {
    //if(player->getSprite().getGlobalBounds().intersects((*it).getTileRect())){
      // Right of the player collision
      if((playerPosition.x + 28 > (*it).getPositionX() && playerPosition.x + 28 < (*it).getPositionX() + 32) &&
        ((playerPosition.y > (*it).getPositionY() && playerPosition.y < (*it).getPositionY() + 28) ||
        (playerPosition.y + 28 < (*it).getPositionY() + 32 && playerPosition.y + 28 > (*it).getPositionY()))){
        if(player->getMovement().x > 0.f){
          player->setMovementX(0.f);
        }
      }

      // Left of the player collision
      if((playerPosition.x + 4 < (*it).getPositionX() + 32 && playerPosition.x + 4 > (*it).getPositionX()) &&
        ((playerPosition.y > (*it).getPositionY() && playerPosition.y < (*it).getPositionY() + 28) ||
        (playerPosition.y + 28 < (*it).getPositionY() + 32 && playerPosition.y + 28 > (*it).getPositionY()))){
        if(player->getMovement().x < 0.f){
          player->setMovementX(0.f);
        }
      }

      // Below of the player collision
      if((playerPosition.y + 32 + player->getMovement().y > (*it).getPositionY() && playerPosition.y + 32 < (*it).getPositionY() + 32) &&
        ((playerPosition.x + 8 > (*it).getPositionX() && playerPosition.x + 8 < (*it).getPositionX() + 32) ||
        (playerPosition.x + 26 < (*it).getPositionX() + 32 && playerPosition.x + 26 > (*it).getPositionX()))){
        if(playerPosition.y + 32 + player->getMovement().y > (*it).getPositionY()){
          player->setSpritePosition(player->getSprite().getPosition().x, (*it).getPositionY() - 32);
        }
        if(player->getMovement().y > 0.f){
          player->setMovementY(0.f);
          player->setIsJumping(false);
        }
      }

      // Above of the player collision
      if((playerPosition.y < (*it).getPositionY() + 32 && playerPosition.y > (*it).getPositionY()) &&
        ((playerPosition.x + 8 > (*it).getPositionX() && playerPosition.x + 8 < (*it).getPositionX() + 32) ||
        (playerPosition.x + 26 < (*it).getPositionX() + 32 && playerPosition.x + 26 > (*it).getPositionX()))){
        player->setMovementY(player->getGravity() + 1);
      }
    //}
  }
}

void TileSet::verifyBulletCollision(std::vector<Bullet>* bullets){
  for (uint i = 0; i < bullets->size(); i++) {
    Bullet *cur = &bullets->at(i);
    for(uint j = 0; j < this->tileSet.size(); j++){
      sf::FloatRect boundingBox = cur->getBullet().getGlobalBounds();
      if(this->tileSet[j].getTileRect().intersects(boundingBox)){
        cur->shouldBeDestroyed(true);
      }
    }
  }
}
