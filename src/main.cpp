#include "game_scene.hpp"
#include "gs2d/core.hpp"

int main() {
  gs::App app(800, 600, "Vulnus");
  app.app_start(new GameScene());
}
