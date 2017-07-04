#ifndef _MENUBUTTON_HPP_
#define _MENUBUTTON_HPP_

#include <SFML/Graphics.hpp>
#include "spritedentity.hpp"

class MenuButton : public SpritedEntity {
private:
	bool focused;

public:
	MenuButton(sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH);
	void setFocused(bool focused);
	bool isFocused();
};

#endif