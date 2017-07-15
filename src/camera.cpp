#include "camera.hpp"

Camera::Camera(float xCenter, float yCenter, float w, float h, float zoom) : view(sf::Vector2f(xCenter, yCenter), sf::Vector2f(w, h)){
  this->w = w;
  this->h = h;
  cameraZoom(zoom);
}

void Camera::resetCameraPosition(){
  this->view.setCenter(400,300);
}

void Camera::calculateCameraXPosition(float& cameraXPosition, sf::Vector2f playerSpritePos, sf::Vector2f viewSize, sf::Vector2u levelSize){
  if((playerSpritePos.x + 16) - viewSize.x < 0){
    cameraXPosition = viewSize.x;
  }

  if((playerSpritePos.x + 16) + viewSize.x > levelSize.x){
    cameraXPosition = levelSize.x - viewSize.x;
  }
}

void Camera::calculateCameraYPosition(float& cameraYPosition, sf::Vector2f playerSpritePos, sf::Vector2f viewSize, sf::Vector2u levelSize ){
  if((playerSpritePos.y + 16) - viewSize.y < 0){
    cameraYPosition = viewSize.y;
  }

  if((playerSpritePos.y + 16) + viewSize.y > levelSize.y){
    cameraYPosition = levelSize.y - viewSize.y;
  }
}

void Camera::getToPlayer(const Player& player, sf::Vector2u levelSize){
  sf::Vector2f playerSpritePos = player.getSpritePosition();
  sf::Vector2f viewSize(this->w, this->h);

  float cameraXPosition = playerSpritePos.x + 16;
  float cameraYPosition = playerSpritePos.y + 16;

  calculateCameraXPosition(cameraXPosition, playerSpritePos, viewSize, levelSize);
  calculateCameraYPosition(cameraYPosition, playerSpritePos, viewSize, levelSize);

  this->view.setCenter(cameraXPosition, cameraYPosition);
}

void Camera::cameraZoom(float zoom){
  this->view.zoom(zoom);
}

sf::View Camera::getView() const{
  return this->view;
}
