#include "tileset.hpp"

TileSet::TileSet(int w, int h, int cellSize) : grid(w, h, cellSize){ }

void TileSet::addTile(Tile tile){
  this->grid.addTile(tile);
}

enum TileSet::collisionCase TileSet::getCollisionCase(sf::Vector2f playerPosition, Tile it, sf::Vector2f playerMovement){
  if((playerPosition.x + 28 > it.getPositionX() && playerPosition.x + 28 < it.getPositionX() + 32) &&
    ((playerPosition.y > it.getPositionY() && playerPosition.y < it.getPositionY() + 28) ||
    (playerPosition.y + 28 < it.getPositionY() + 32 && playerPosition.y + 28 > it.getPositionY()))){
    return rightWallCollision;
  }

  if((playerPosition.x + 4 < it.getPositionX() + 32 && playerPosition.x + 4 > it.getPositionX()) &&
    ((playerPosition.y > it.getPositionY() && playerPosition.y < it.getPositionY() + 28) ||
    (playerPosition.y + 28 < it.getPositionY() + 32 && playerPosition.y + 28 > it.getPositionY()))){
    return leftWallCollision;
  }

  if((playerPosition.y + 32 + playerMovement.y > it.getPositionY() && playerPosition.y + 32 < it.getPositionY() + 32) &&
    ((playerPosition.x + 8 > it.getPositionX() && playerPosition.x + 8 < it.getPositionX() + 32) ||
    (playerPosition.x + 26 < it.getPositionX() + 32 && playerPosition.x + 26 > it.getPositionX()))){
      return groundCollision;
    }

  if((playerPosition.y < it.getPositionY() + 32 && playerPosition.y > it.getPositionY()) &&
      ((playerPosition.x + 8 > it.getPositionX() && playerPosition.x + 8 < it.getPositionX() + 32) ||
      (playerPosition.x + 26 < it.getPositionX() + 32 && playerPosition.x + 26 > it.getPositionX()))){
      return roofCollision;
    }
  return noCollision;
}

void TileSet::verifyPlayerCollision(Player* player){
  sf::Vector2f playerPosition = player->getSprite().getPosition();
  sf::Vector2f playerMovement = player->getMovement();

  std::vector<Unity> unities = grid.getUnitiesOnPosition(playerPosition);

  for(std::vector<Unity>::iterator unitiesIt = unities.begin(); unitiesIt != unities.end(); ++unitiesIt){
    Unity unity = *unitiesIt;
    //int i = 1;

    for(std::vector<Tile>::iterator it = unity.tiles.begin(); it != unity.tiles.end(); ++it){
      //std::cout << "I'm verifying tile n = " << i << std::endl;
      //i++;
      switch(getCollisionCase(playerPosition, *it, playerMovement)){
        case rightWallCollision:
        if(player->getMovement().x > 0.f){
          player->setMovementX(0.f);
        }
        break;
        case leftWallCollision:
        if(player->getMovement().x < 0.f){
          player->setMovementX(0.f);
        }
        break;
        case groundCollision:
        if(playerPosition.y + 32 + player->getMovement().y > (*it).getPositionY()){
          player->setSpritePosition(player->getSprite().getPosition().x, (*it).getPositionY() - 32);
        }
        if(player->getMovement().y > 0.f){
          player->setMovementY(0.f);
          player->setIsJumping(false);
        }
        break;
        case roofCollision:
        player->setMovementY(player->getGravity() + 1);
        break;
        case noCollision:
        break;
      }
    }
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
