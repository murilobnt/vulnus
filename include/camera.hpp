#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

// # External
#include <SFML/Graphics.hpp>
#include <iostream>

// # Internal
#include "player.hpp"

class Camera{
private:
  // The view of the camera
  sf::View view;
  // The width of the camera
  float w;
  // The height of the camera
  float h;

  void calculateCameraXPosition(float& cameraXPosition, sf::Vector2f playerSpritePos, sf::Vector2f viewSize, sf::Vector2u levelSize);
  
  void calculateCameraYPosition(float& cameraYPosition, sf::Vector2f playerSpritePos, sf::Vector2f viewSize, sf::Vector2u levelSize );

public:
  /**
   * Constructor.
   * @param xCenter the center of the camera in x axis
   * @param yCenter the center of the camera in y axis
   * @param w the width of the camera
   * @param h the height of the camera
   * @param zoom the zoom of the camera
   */
  Camera(float xCenter, float yCenter, float w, float h, float zoom);

  /**
   * Get the camera to player.
   * @param player the player
   * @param levelSize the size of the level
   */
  void getToPlayer(const Player& player, sf::Vector2u levelSize);

  /**
   * Apply zoom on camera.
   * @param zoom the zoom to be applied
   */
  void cameraZoom(float zoom);

  /**
   * Get the view of the camera.
   * @return the view of the camera
   */
  sf::View getObject() const;
};

#endif
