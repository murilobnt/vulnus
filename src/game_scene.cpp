#include "game_scene.hpp"

void GameScene::start() {
  gs::TextureLoader::set_texture_from_file(texture, "assets/player_t.png");
  player = Player(texture, sf::Vector2f(400, 300));
  time_handlers.push_back(player.get_time_handler());
}

void GameScene::update() {
  player.control_entity(get_delta_time());
  player.time_trigger();
  player.move();
}

void GameScene::draw_entities() { app_window->draw(player.get_sprite()); }
