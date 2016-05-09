#ifndef _TILESET_H_
#define _TILESET_H_

#include <vector>
#include <iostream>
#include "Tile.h"
#include "Player.h"
#include "Bullet.h"
#include "Grid.h"

class TileSet{
private:
  // The set of tiles
  std::vector<Tile> tileSet;

public:
  /**
   * Constructor.
   */
  TileSet();

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
