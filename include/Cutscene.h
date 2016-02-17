#ifndef _CUTSCENE_H_
#define _CUTSCENE_H_

#include <SFML/Graphics.hpp>
#include <string>

class Cutscene{
private:
  sf::Sprite sprite;
  int id;
  bool active;
  sf::Text text;
  sf::Font font;
  bool typing;

public:
  Cutscene(int id, sf::Texture const& texture);
  bool isActive();
  void setActive(int id, bool active);
  sf::Text getText();
  void setTextToCamera(sf::View view);
  void proceedCutscene(sf::Keyboard::Key key);
};

#endif
