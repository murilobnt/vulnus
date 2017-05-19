#ifndef _TILESET_HPP_
#define _TILESET_HPP_

// # External
#include <vector>
#include <iostream>

// # Internal
#include "tile.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "grid.hpp"

class TileSet{
private:
  // The set of tiles
  std::vector<Tile> tileSet;
  Grid grid;

  enum collisionCase{
    groundCollision,
    roofCollision,
    leftWallCollision,
    rightWallCollision,
    noCollision
  };

  enum collisionCase getCollisionCase(sf::Vector2f playerPosition, Tile it, sf::Vector2f playerMovement);

public:
  /**
   * Constructor.
   */
  TileSet(int w, int h, int cellSize);

  /**
   * Add a tile to the set.
   * @param tile the tile to be added
   */
  void addTile(Tile tile);

  /**
   * Verify the collision of the player.
   * @param player the player to check the collision
   */
  void verifyPlayerCollision(Player* player);

  /**
   * Verify the collision of every bullet in a set.
   * @param bullets the set of the bullets
   */
  void verifyBulletCollision(std::vector<Bullet>* bullets);
};

#endif
