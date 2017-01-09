#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
#include <cmath>

#include "Tile.h"

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