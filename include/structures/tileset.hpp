#ifndef _TILESET_HPP_
#define _TILESET_HPP_

// # External
#include <vector>

// # Internal
#include "structures/tile.hpp"
#include "structures/tilegrid.hpp"
#include "generics/aliveentity.hpp"

class TileSet{
private:
  // The set of tiles
  std::vector<Tile> tileSet;
  TileGrid grid;

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
  void verifyEntityCollision(AliveEntity* player);

  TileGrid getTileGrid() const;
};

#endif
