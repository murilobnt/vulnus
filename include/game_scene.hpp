#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "gs2d/scene.hpp"
#include "player.hpp"

class GameScene : public gs::Scene {

private:
  sf::Texture texture;
  Player player;

public:
  void start();
  void update();
  void draw_entities();
};

#endif
