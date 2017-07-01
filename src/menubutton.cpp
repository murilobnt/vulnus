#include "menubutton.hpp"

MenuButton::MenuButton(sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY){
	this->spriteInitX = spriteInitX;
	this->spriteEndX = spriteEndX;
	this->spriteInitY = spriteInitY;
	this->spriteEndY = spriteEndY;

	setFocused(false);

	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(spriteX, spriteY, spriteW, spriteH));
}

void MenuButton::setFocused(bool focused){
	if(focused == true){
		sprite.setColor(sf::Color::Magenta);
	} else {
		sprite.setColor(sf::Color(0, 0, 0, 255));
	}
	this->focused = focused;
}

bool MenuButton::isFocused(){
	return focused;
}