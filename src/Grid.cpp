#include "Grid.h"

Grid::Grid(int w, int h, int cellSize){
  this->cellSize = cellSize;

  this->xCells = ceil((float)w / cellSize);
  this->yCells = ceil((float)h / cellSize);

  this->cells.resize(xCells * yCells);
  this->cells.push_back(Cell());
}

Cell* Grid::getCell(int x, int y){
  return &this->cells[x + y * xCells];
}

Cell Grid::getCell(sf::Vector2f playerPos){
  int playerX = (int)((playerPos.x + 16)/cellSize);
  int playerY = (int)((playerPos.y)/cellSize);

  if(playerX < 0){
    playerX = 0;
  }
  if(playerX > xCells){
    playerX = xCells;
  }

  if(playerY < 0){
    playerY = 0;
  }

  if(playerY > yCells){
    playerY = yCells;
  }

  if(playerX + playerY * xCells > (xCells * yCells)){
    return this->cells[xCells * yCells - 1];
  }

  std::cout << "I'm returning cell[" << playerX + playerY * xCells << "]." << std::endl;

  return this->cells[playerX + playerY * xCells];
}

void Grid::addTile(Tile tile){
  int tileX = (int)(tile.getPositionX()/cellSize);
  int tileY = (int)(tile.getPositionY()/cellSize);

  Cell* cell = getCell(tileX, tileY);
  cell->tiles.push_back(tile);
}
