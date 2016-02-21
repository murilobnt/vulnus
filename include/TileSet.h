#ifndef _TILESET_H_
#define _TILESET_H_

#include <vector>
#include <iostream>
#include "Tile.h"
#include "Player.h"
#include "Bullet.h"

class TileSet{
private:
  std::vector<Tile> tileSet;

public:
  TileSet();
  void addTile(Tile tile);
  void verifyPlayerCollision(Player* player);
  void verifyBulletCollision(std::vector<Bullet>* bullets);
};

#endif
