#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <gs2d/scene_components.hpp>

class Player : public gs::IBControlableEntity,
               public gs::GameObject,
               public gs::AnimatedEntity {
private:
  bool right;

public:
  Player();
  Player(sf::Texture const &texture,
         sf::Vector2f position = sf::Vector2f(0, 0));
  void animate();
  void control_entity(float delta_time);
  void jump(float delta_time);
  void apply_gravity(float delta_time);
  void move();
  void move(float delta_time);
};

#endif
