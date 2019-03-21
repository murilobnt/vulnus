#include "game_scene.hpp"

void GameScene::start() {
  gs::TextureLoader::set_texture_from_file(texture, "assets/player_t.png");
  player = Player(texture, sf::Vector2f(400, 300));
  time_handlers.push_back(player.get_time_handler());
  speed_display.setFillColor(sf::Color::Green);
  speed_display.setPosition(sf::Vector2f(20, app_window->getSize().y - 60));
  speed_display.setSize(sf::Vector2f(0, 20));
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-R.ttf");
  text.setFont(font);
  text.setCharacterSize(20);
  text.setFillColor(sf::Color::White);
  text.setPosition(sf::Vector2f(20, app_window->getSize().y - 40));
}

void GameScene::update() {
  player.apply_gravity(get_delta_time());
  player.control_entity(get_delta_time());
  player.time_trigger();
  speed_display.setSize(
      sf::Vector2f(player.get_speed(get_delta_time()) / 10, 20));
  text.setString(std::to_string(player.get_speed(get_delta_time())));
  player.move(get_delta_time());
}

void GameScene::draw_entities() {
  app_window->draw(player.get_sprite());
  app_window->draw(speed_display);
  app_window->draw(text);
}
