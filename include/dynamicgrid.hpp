#ifndef _DYNAMICGRID_HPP_
#define _DYNAMICGRID_HPP_

#include <SFML/Graphics.hpp>

#include "abstractgrid.hpp"

class DynamicGrid : public AbstractGrid {
public:
	DynamicGrid(int w, int h, int unitySize);
	DynamicGrid();
	int getQuad(sf::Vector2f position) const;
	int getQuad(int x, int y) const;
};

#endif