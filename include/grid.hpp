#ifndef _GRID_HPP_
#define _GRID_HPP_

// # External
#include <vector>
#include <cmath>

// # Internal
#include "tile.hpp"

class Unity {
public:
  std::vector<Tile> tiles;
};

class Grid {
private:
  int w;
  int h;
  int unitySize;

  int xCells;
  int yCells;

  std::vector<Unity> unities;

  sf::Vector2i checkCondition(sf::Vector2i before);
public:
  Grid(int w, int h, int unitySize);
  Unity* getUnity(int x, int y);
  void addTile(Tile tile);
  std::vector<Unity> getUnitiesOnPosition(sf::Vector2f playerUpperLeftPos);
};

#endif