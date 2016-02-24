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
  // The sprite of the text box
  sf::Sprite sprite;
  // The id of the cutscene
  int id;
  // The verifier to check if the cutscene is active or not
  bool active;
  // The verifier to check if the text is still being constructed
  bool typing;
  // The verifier to check if the player has not reached the end of the cutscene yet
  bool keepAdvancing;
  // The verifier to check if the player is still pressing the key to proceed the cutscene
  bool pressed;
  // The font of the text to be drawn
  sf::Font font;
  // The database of all cutscenes
  CutsceneDatabase database;
  // The iterator to pass through all cutscene stages
  int iterator;
  // The set of the texts of the current cutscene
  std::vector<std::string> current;
  // The text to be drawn
  sf::Text text;

public:
  /**
   * Constructor.
   * @param id the id of the cutscene
   * @param texture the texture of the text box
   * @param startCutscene the verifier to check if the cutscene start when the object is constructed or not
   */
  Cutscene(int id, sf::Texture const& texture, bool startCutscene);

  /**
   * Check if the cutscene is active.
   * @return if the cutscene is active
   */
  bool isActive();

  /**
   * Set the activity cutscene by its id.
   * @param id the id of the cutscene
   */
  void setActive(int id);

  /**
   * Set the activity with the id already set.
   * @param active the new state of the activity of the cutscene
   */
  void setActive(bool active);

  /**
   * Get the text.
   * @return the text
   */
  sf::Text getText();

  /**
   * Set the text position to the camera.
   * @param view the view of the camera
   */
  void setTextToCamera(sf::View view);

  /**
   * Check the player input.
   * @param key the key pressed by the user during the cutscene
   * @param pressed the verifier to check if the user isn't constantly pressing the key
   */
  void proceedCutscene(sf::Keyboard::Key key, bool pressed);

  /**
   * Proceed on the cutscene.
   * @param id the id of the cutscene
   */
  void refreshText(int id);

  /**
   * Draw the text.
   * @param target the window target to draw the text
   */
  void drawText(sf::RenderTarget& target);

  /**
   * Draw the background.
   * @param target the window target to draw the background
   */
  void drawCutsceneBackground(sf::RenderTarget& target);
};

#endif
