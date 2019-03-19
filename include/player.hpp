#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <gs2d/scene_components.hpp>
#include <iostream>

#include "facing_position.hpp"
#include "movement_direction.hpp"

class Player : public gs::IBControlableEntity,
               public gs::GameObject,
               public gs::AnimatedEntity {
private:
  FacingPosition f_p;
  MovementDirection m_d;
  MovementDirection last_m_d;
  bool on_ground;
  float m_i;
  bool ac_x_lock;
  bool opposite;

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
