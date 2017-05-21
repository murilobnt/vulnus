#include "tileset.hpp"

TileSet::TileSet(int w, int h, int cellSize) : grid(w, h, cellSize){ }

void TileSet::addTile(Tile tile){
  this->grid.addTile(tile);
}

void TileSet::verifyPlayerCollision(Player* player){
  sf::Sprite playerSprite = player->getSprite();
  sf::Vector2f playerPosition = playerSprite.getPosition();
  sf::Vector2f playerMovement = player->getMovement();

  std::vector<Unity> unities = grid.getUnitiesOnPosition(playerPosition);

  for(std::vector<Unity>::iterator unitiesIt = unities.begin(); unitiesIt != unities.end(); ++unitiesIt){
    Unity unity = *unitiesIt;

    for(std::vector<Tile>::iterator it = unity.tiles.begin(); it != unity.tiles.end(); ++it){
      sf::FloatRect tileRect = (*it).getTileRect();

      if(tileRect.intersects(playerSprite.getGlobalBounds())){
        sf::Vector2f playerAuxPosXRight(playerPosition.x + 32 + playerMovement.x, playerPosition.y + 4);
        sf::Vector2f playerAuxPosXRight2(playerPosition.x + 32 + playerMovement.x, playerPosition.y + 20);

        sf::Vector2f playerAuxPosXLeft(playerPosition.x + playerMovement.x, playerPosition.y + 4);
        sf::Vector2f playerAuxPosXLeft2(playerPosition.x + playerMovement.x, playerPosition.y + 20);

        sf::Vector2f playerAuxPosYUp(playerPosition.x + 6, playerPosition.y + playerMovement.y);
        sf::Vector2f playerAuxPosYUp2(playerPosition.x + 26, playerPosition.y + playerMovement.y);

        sf::Vector2f playerAuxPosYDown(playerPosition.x + 6, playerPosition.y + 32 + playerMovement.y);
        sf::Vector2f playerAuxPosYDown2(playerPosition.x + 26, playerPosition.y + 32 + playerMovement.y);

        if(tileRect.contains(playerAuxPosXRight) || tileRect.contains(playerAuxPosXRight2)){
          if(playerMovement.x > 0.f){
              player->setMovementX(0.f);
              player->setSpritePosition((*it).getPositionX() - 32, player->getSprite().getPosition().y);
          }
        }

        if(tileRect.contains(playerAuxPosXLeft) || tileRect.contains(playerAuxPosXLeft2)){
          if (playerMovement.x < 0.f){
              player->setMovementX(0.f);
              player->setSpritePosition((*it).getPositionX() + 32, player->getSprite().getPosition().y);
          }
        }

        if(tileRect.contains(playerAuxPosYDown) || tileRect.contains(playerAuxPosYDown2)){
          if(playerMovement.y > 0.f){
              player->setMovementY(0.f);
              player->setIsJumping(false);
              player->setSpritePosition(player->getSprite().getPosition().x, (*it).getPositionY() - 32);
          }
        }

        if(tileRect.contains(playerAuxPosYUp) || tileRect.contains(playerAuxPosYUp2)){
          if (playerMovement.y < 0.f){
              player->setMovementY(player->getGravity() + 1);
              player->setSpritePosition(player->getSprite().getPosition().x, (*it).getPositionY() + 32);
          }
        }
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
