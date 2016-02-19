#ifndef _CUTSCENE_H_
#define _CUTSCENE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "CutsceneDatabase.h"
#include <vector>
#include <string>
//#include "CutsceneText.h"
//#include "CutscenesDatabase.h"

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
  //CutsceneText theTexts;

public:
  sf::Text text;
  Cutscene(int id, sf::Texture const& texture);
  bool isActive();
  void setActive(int id, bool active);
  void setActive(bool active);
  sf::Text getText();
  void setTextToCamera(sf::View view);
  void proceedCutscene(sf::Keyboard::Key key, bool pressed);
  void refreshText(int id);
  //void refreshText();
  //void draw(sf::RenderTarget& target);
  //void switchCutsceneById(int id, CutscenesDatabase datas);
};

#endif
