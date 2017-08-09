#include "entities/cutscene/cutscene.hpp"

Cutscene::Cutscene(int id, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, bool startCutscene) : 
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH)
{
  this->id = id;
  this->font.loadFromFile("fonts/Ubuntu-C.tff");

  setActive(id);
  refreshText(id);
}

bool Cutscene::isActive(){
  return active;
}

void Cutscene::setActive(int id){
  this->id = id;
  setActive(true);
}

void Cutscene::setActive(bool active){
  this->active = active;
  this->textDisplayIterator = 0;
  this->keepAdvancing = true;
}

sf::Text Cutscene::getText() const{
  return this->text;
}

sf::Vector2f Cutscene::calculateTextBoxPosition(sf::View view){
  return sf::Vector2f(view.getCenter().x - (getSpriteLocalBounds().width/2), view.getCenter().y + (view.getSize().y/2) - 80);
}

sf::Vector2f Cutscene::calculateTextPosition(sf::View view){
  return sf::Vector2f(view.getCenter().x - (this->text.getLocalBounds().width/2), view.getCenter().y + (view.getSize().y/2) - 60);
}

void Cutscene::setTextToCamera(sf::View view){
  setSpritePosition(calculateTextBoxPosition(view));
  this->text.setPosition(calculateTextPosition(view));
}

void Cutscene::proceedCutscene(sf::Keyboard::Key key, bool continueButtonIsPressed){
  if(!this->keepAdvancing){
    this->setActive(false);
  }

  if(key == sf::Keyboard::X && !this->continueButtonIsPressed){
    refreshText(this->id);
  }

  this->continueButtonIsPressed = continueButtonIsPressed;
}

void Cutscene::refreshText(int id){
  if(this->currentCutscene != this->database.getCutsceneById(id)){
    this->currentCutscene = this->database.getCutsceneById(id);
  }

  if(this->textDisplayIterator >= this->currentCutscene.size()){
    this->keepAdvancing = false;
    return;
  }

  this->text = sf::Text(this->currentCutscene[this->textDisplayIterator], font);

  this->text.setCharacterSize(20);
	this->text.setColor(sf::Color::White);
  this->textDisplayIterator++;
}

void Cutscene::drawText(sf::RenderTarget& target){
  target.draw(text);
}

void Cutscene::drawCutsceneBackground(sf::RenderTarget& target){
  target.draw(getSprite());
}

void Cutscene::controlEntity(sf::Keyboard::Key key, bool release){
  proceedCutscene(key, !release);
}