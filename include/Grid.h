#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
#include <cmath>
#include "Tile.h"
#include <iostream>

struct Cell{
  // The tiles on the cell
  std::vector<Tile> tiles;
};

class Grid{
private:
  // The cells of the grid
  std::vector<Cell> cells;

  // The size of every cell
  int cellSize;

  // The number of cells on x axis
  int xCells;

  // The number of cells on y axis
  int yCells;

public:
  /**
	 * Constructor.
   * @param cellSize the size of every cell
	 */
  Grid(int w, int h, int cellSize);

  /**
	 * Get a cell of certain position.
   * @param x the x position of the cell
   * @param y the y position of the cell
   * @return the cell of the passed postion
	 */
  Cell* getCell(int x, int y);

  Cell getCell(sf::Vector2f playerPos);

  void addTile(Tile tile);
};

#endif
