#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
#include "Tile.h"

struct Cell{
  std::vector<Tile> tiles;
};

class Grid{
private:
  std::vector<Cell> cells;
  int cellSize;
  int w;
  int h;
  int xCells;
  int yCells;

public:
  Grid(int w, int h, int cellSize);
  Cell getCell(int x, int y);
};

#endif
