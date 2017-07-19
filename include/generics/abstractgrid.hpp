#ifndef _ABSTRACTGRID_HPP_
#define _ABSTRACTGRID_HPP_

#include <cmath>

class AbstractGrid{
protected:
  int w;
  int h;
  int unitySize;

  int xCells;
  int yCells;

public:
	AbstractGrid(int w, int h, int unitySize);
};

#endif