#include "menubutton.hpp"

MenuButton::MenuButton(float x, float y, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH) :
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH) {
	setFocused(false);
	
	setSpritePosition(x, y);
}

void MenuButton::setFocused(bool focused){
	if(focused == true){
		setSpriteColor(sf::Color::Cyan);
	} else {
		setSpriteColor(sf::Color(255, 255, 255));
	}
	this->focused = focused;
}

bool MenuButton::isFocused(){
	return focused;
}

sf::Text& MenuButton::getButtonLabel(){
	return this->buttonLabel;
}

void MenuButton::initText(sf::Font& sceneFont, std::string buttonText){
	this->buttonLabel.setFont(sceneFont);
	this->buttonLabel.setString(buttonText);

	this->buttonLabel.setPosition(getSpritePosition().x + getSpriteLocalBounds().width/2 - this->buttonLabel.getLocalBounds().width/2, getSpritePosition().y);
}