#ifndef _MENUBUTTON_HPP_
#define _MENUBUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <string>

#include "generics/spritedentity.hpp"

class MenuButton : public SpritedEntity {
private:
	bool focused;
	sf::Text buttonLabel;

public:
	MenuButton(float x, float y, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH);
	void setFocused(bool focused);
	bool isFocused();
	sf::Text& getButtonLabel();
	void initText(sf::Font& sceneFont, std::string buttonText);
};

#endif