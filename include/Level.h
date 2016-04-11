#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "TileMap.h"
#include "Enemy.h"
#include <vector>
#include <iostream>

class Level{
private:
  TileMap tileMap;
  std::vector<Enemy> enemies;
  void loadLevelOne(sf::Texture const& enemiesTexture);

public:
  Level(int id, sf::Texture const& enemiesTexture);
  TileMap getTileMap();
  void loadLevel(int id, sf::Texture const& enemiesTexture);
  void drawEnemies(sf::RenderTarget& target);
};

#endif
