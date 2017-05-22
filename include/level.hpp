#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

// # External
#include <vector>
#include <iostream>

// # Internal
#include "enemy.hpp"
#include "tilemap.hpp"

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
  std::vector<Enemy>* getEnemies();
};

#endif
