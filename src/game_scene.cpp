#include "game_scene.hpp"

void GameScene::start() {
  gs::TextureLoader::set_texture_from_file(texture, "assets/player_t.png", 64,
                                           64);
  player = Player(texture);
  player.set_sprite_position(sf::Vector2f(400, 300));
  time_handlers.push_back(&player.get_animation_time_handler());
}

void GameScene::update() {
  player.control_entity(get_delta_time());
  if (player.get_animation_time_handler().time_to_update()) {
    player.animate();
  }
  player.move();
}

void GameScene::draw_entities() { app_window->draw(player.get_sprite()); }

// gs::TextureLoader::set_texture_from_file(
//      char_texture, "assets/images/link_edit4040.png", 400, 320);
//  character = Character(char_texture, sf::Vector2i(0, 0), sf::Vector2i(40,
//  40),
//                        sf::Vector2i(0, 400), sf::Vector2i(160, 280), 20);
