#include "player.hpp"

Player::Player() { right = true; }

Player::Player(sf::Texture const &texture, sf::Vector2f position)
    : GameObject(texture, sf::Vector2i(32, 32)),
      AnimatedEntity(sf::Vector2i(0, 64), sf::Vector2i(0, 64), 10) {
  right = true;
  set_sprite_position(position);
}

void Player::animate() {
  if (movement.x > 0)
    apply_animation_by_row(this, 0);
  else if (movement.x < 0)
    apply_animation_by_row(this, 1);
  else
    right ? configure_sprite_rect(0, 0) : configure_sprite_rect(0, 32);
}

void Player::jump(float delta_time) { movement.y = -400 * delta_time; }

void Player::apply_gravity(float delta_time) {
  if (get_sprite_position().y < 300)
    movement.y += 20 * delta_time;
  else
    movement.y = 0;
}

void Player::control_entity(float delta_time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    movement.x = -200 * delta_time;
    right = false;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    movement.x = 200 * delta_time;
    right = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    jump(delta_time);
  }
}

void Player::move() {
  move_sprite(movement);
  movement = sf::Vector2f(0, movement.y);
}

void Player::move(float delta_time) { move_sprite(movement * delta_time); }
