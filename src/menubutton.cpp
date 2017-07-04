#include "menubutton.hpp"

MenuButton::MenuButton(sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH) :
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH) {
	setFocused(false);
}

void MenuButton::setFocused(bool focused){
	if(focused == true){
		setSpriteColor(sf::Color::Magenta);
	} else {
		setSpriteColor(sf::Color(0, 0, 0, 255));
	}
	this->focused = focused;
}

bool MenuButton::isFocused(){
	return focused;
}