#include "Grid.h"

Grid::Grid(int w, int h, int cellSize){
  this->w = w;
  this->h = h;
  this->cellSize = cellSize;
  xCells = ceil((float)w/cellSize);
  yCells = ceil((float)h/cellSize);

  cells.resize(yCells * xCells);
}

Cell Grid::getCell(int x, int y){

  if(x < 0){
    x = 0;
  }
  if(x > xCells){
    x = xCells - 1;
  }

  if(y < 0){
    y = 0;
  }
  if(y > yCells){
    y = yCells - 1;
  }

  return cells[y * xCells + xCells];
}
