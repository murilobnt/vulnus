#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <SFML/Graphics.hpp>
#include "Player.h"

class Camera{
private:
  sf::View view;
  float w;
  float h;

public:
  Camera(float xCenter, float yCenter, float w, float h, float zoom);
  void getToPlayer(Player player, sf::Vector2u levelSize);
  void cameraZoom(float zoom);
  sf::View getObject();
};

#endif
