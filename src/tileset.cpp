#include "structures/tileset.hpp"

TileSet::TileSet(int w, int h, int cellSize) : grid(w, h, cellSize){ }

void TileSet::addTile(Tile tile){
  this->grid.addTile(tile);
}

void TileSet::verifyEntityCollision(AliveEntity* player){
  sf::Sprite playerSprite = player->getSprite();
  sf::Vector2f playerPosition = playerSprite.getPosition();
  sf::Vector2f playerMovement = player->getMovement();
  sf::FloatRect playerSize = playerSprite.getGlobalBounds();

  std::vector<Unity> unities = grid.getUnitiesOnPosition(playerPosition);

  for(std::vector<Unity>::iterator unitiesIt = unities.begin(); unitiesIt != unities.end(); ++unitiesIt){
    Unity unity = *unitiesIt;

    for(std::vector<Tile>::iterator it = unity.tiles.begin(); it != unity.tiles.end(); ++it){
      sf::FloatRect tileRect = (*it).getTileRect();

      if(playerMovement.x > 0.f){
        sf::RectangleShape nextMovement(sf::Vector2f(playerSize.width + playerMovement.x, playerSize.height));
        nextMovement.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y));
        if(tileRect.intersects(nextMovement.getGlobalBounds())){
          player->setMovementX(0.f);
          player->setSpritePosition((*it).getPositionX() - 32, player->getSpritePosition().y);
        }
      }else if(playerMovement.x < 0.f){
        sf::RectangleShape nextMovement(sf::Vector2f(playerSize.width + (-playerMovement.x), playerSize.height));
        nextMovement.setPosition(sf::Vector2f(playerPosition.x + 32 - (playerSize.width + (-playerMovement.x)), playerPosition.y));
        if(tileRect.intersects(nextMovement.getGlobalBounds())){
          player->setMovementX(0.f);
          player->setSpritePosition((*it).getPositionX() + 32, player->getSpritePosition().y);
        }
      }

      if(playerMovement.y > 0.f){
        sf::RectangleShape nextMovement(sf::Vector2f(playerSize.width, playerSize.height + playerMovement.y));
        nextMovement.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y));
        if(tileRect.intersects(nextMovement.getGlobalBounds())){
          player->setMovementY(0.f);
          player->setDoubleJump(false);
          player->setIsJumping(false);
          player->setSpritePosition(player->getSpritePosition().x, (*it).getPositionY() - 32);
        }
      } else if(playerMovement.y < 0.f){
        sf::RectangleShape nextMovement(sf::Vector2f(playerSize.width, (int)(playerSize.height - playerMovement.y)));
        nextMovement.setPosition(sf::Vector2f(playerPosition.x, playerPosition.y + 32 - (int)(playerSize.height - playerMovement.y)));
        if(tileRect.intersects(nextMovement.getGlobalBounds())){
          player->setMovementY(player->getGravity());
          player->setSpritePosition(player->getSpritePosition().x, (*it).getPositionY() + 32);
        }
      } // This one shall be erased!
    }
  }
}

TileGrid TileSet::getTileGrid() const{
  return this->grid;
}