#include "Cutscene.h"

Cutscene::Cutscene(int id, sf::Texture const& texture){
  this->id = id;
  //this->sprite.setTexture(texture);
  this->font.loadFromFile("Ubuntu-C.tff");
  std::string theText;

  switch (id) {
    case 0:
      theText = "Este é apenas um teste! A primeira cutscene!";
      break;
    default:
      theText = "O default foi acionado!";
      break;
      text = sf::Text(theText, font);
  }

  this->text.setCharacterSize(15);
	this->text.setStyle(sf::Text::Bold);
	this->text.setColor(sf::Color::Red);
}

bool Cutscene::isActive(){
  return active;
}

void Cutscene::setActive(int id, bool active){
  this->id = id;
  this->active = active;
}

sf::Text Cutscene::getText(){
  return this->text;
}

void Cutscene::setTextToCamera(sf::View view){
  this->text.setPosition(sf::Vector2f(view.getSize().x/2, view.getSize().y - 30));
}

void Cutscene::proceedCutscene(sf::Keyboard::Key key){
  if(key == sf::Keyboard::X){
    this->active = false;
  }
}
