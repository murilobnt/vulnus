#ifndef _CUTSCENE_H_
#define _CUTSCENE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "CutsceneDatabase.h"
#include <vector>
#include <string>

class Cutscene{
private:
  sf::Sprite sprite;
  int id;
  bool active;
  bool typing;
  bool keepAdvancing;
  bool pressed;
  sf::Font font;
  CutsceneDatabase database;
  int iterator;
  std::vector<std::string> current;
  sf::Text text;

public:
  Cutscene(int id, sf::Texture const& texture);
  bool isActive();
  void setActive(int id, bool active);
  void setActive(bool active);
  sf::Text getText();
  void setTextToCamera(sf::View view);
  void proceedCutscene(sf::Keyboard::Key key, bool pressed);
  void refreshText(int id);
  void drawText(sf::RenderTarget& target);
  void drawCutsceneBackground(sf::RenderTarget& target);
};

#endif
