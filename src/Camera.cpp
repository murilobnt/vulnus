#include <Camera.h>

Camera::Camera(float xCenter, float yCenter, float w, float h, float zoom) : view(sf::Vector2f(xCenter, yCenter), sf::Vector2f(w, h)){
  this->w = w;
  this->h = h;
  cameraZoom(zoom);
}

void Camera::getToPlayer(Player player, sf::Vector2u levelSize){
  sf::Vector2f playerSpritePos = player.getSprite().getPosition();
  sf::Vector2f viewSize(this->w, this->h);

  float xToPutCamera = playerSpritePos.x + 16;
  float yToPutCamera = playerSpritePos.y + 16;

  if((playerSpritePos.x + 16) - viewSize.x < 0){
    xToPutCamera = viewSize.x;
    //std::cout << "1" << std::endl;
  }

  if((playerSpritePos.x + 16) + viewSize.x > levelSize.x){
    xToPutCamera = levelSize.x - viewSize.x;
    //std::cout << "2" << std::endl;
  }

  if((playerSpritePos.y + 16) - viewSize.y < 0){
    yToPutCamera = viewSize.y;
    //std::cout << "3" << std::endl;
  }

  if((playerSpritePos.y + 16) + viewSize.y > levelSize.y){
    yToPutCamera = levelSize.y - viewSize.y;
    //std::cout << "4" << std::endl;
  }

  this->view.setCenter(xToPutCamera, yToPutCamera);
}

void Camera::cameraZoom(float zoom){
  this->view.zoom(zoom);
}

sf::View Camera::getObject(){
  return this->view;
}
