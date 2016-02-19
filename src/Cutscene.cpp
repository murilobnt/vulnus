#include "Cutscene.h"

//Cutscene::Cutscene(int id, sf::Texture const& texture, CutscenesDatabase datas) : theTexts(0, datas){
Cutscene::Cutscene(int id, sf::Texture const& texture) : database(){
  this->id = id;
  this->font.loadFromFile("fonts/Ubuntu-C.tff");

  //std::string texto;
  setActive(0, true);

  //this->iterator = 0;
  //this->active = true;
  //this->keepAdvancing = true;

  //this->text = sf::Text(texto, font);

  refreshText(id);
}

bool Cutscene::isActive(){
  return active;
}

void Cutscene::setActive(int id, bool active){
  this->id = id;
  setActive(active);
}

void Cutscene::setActive(bool active){
  this->active = active;
  this->iterator = 0;
  this->keepAdvancing = true;
}

sf::Text Cutscene::getText(){
  return this->text;
}

void Cutscene::setTextToCamera(sf::View view){
  this->text.setPosition(sf::Vector2f(view.getCenter().x - (this->text.getLocalBounds().width/2), view.getCenter().y + (view.getSize().y/2) - 60));
}

void Cutscene::proceedCutscene(sf::Keyboard::Key key, bool pressed){
  if(!this->keepAdvancing){
    this->setActive(false);
  }

  if(key == sf::Keyboard::X && !this->pressed){
    refreshText(this->id);
  }

  this->pressed = pressed;
}

void Cutscene::refreshText(int id){
  if(this->current != this->database.getCutsceneById(id)){
    this->current = this->database.getCutsceneById(id);
  }

  if(this->iterator >= this->current.size()){
    this->keepAdvancing = false;
    return;
  }

  //std::cout << this->current[this->iterator] << std::endl;
  this->text = sf::Text(this->current[this->iterator], font);
  this->text.setCharacterSize(15);
	this->text.setColor(sf::Color::Black);
  this->iterator++;
}

// void Cutscene::draw(sf::RenderTarget& target){
//  target.draw(text);
// }
