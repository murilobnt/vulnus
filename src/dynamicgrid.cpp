#include "structures/dynamicgrid.hpp"

DynamicGrid::DynamicGrid(int w, int h, int unitySize) : AbstractGrid::AbstractGrid(w, h, unitySize){

}

DynamicGrid::DynamicGrid() : AbstractGrid::AbstractGrid(0, 0, 0){

}

int DynamicGrid::getQuad(sf::Vector2f position) const{
	return getQuad(position.x, position.y);
}

int DynamicGrid::getQuad(int x, int y) const{
	return (x/unitySize) + (y/unitySize) * xCells;
}