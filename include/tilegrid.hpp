#ifndef _TILEGRID_HPP_
#define _TILEGRID_HPP_

// # External
#include <vector>
#include <cmath>

// # Internal
#include "tile.hpp"
#include "abstractgrid.hpp"

struct Unity {
public:
  std::vector<Tile> tiles;
};

class TileGrid : public AbstractGrid {
private:
  std::vector<Unity> unities;
  sf::Vector2i checkCondition(sf::Vector2i before);

public:
  TileGrid(int w, int h, int unitySize);
  Unity* getUnity(int x, int y);
  void addTile(Tile tile);
  std::vector<Unity> getUnitiesOnPosition(sf::Vector2f playerUpperLeftPos);
};

#endif