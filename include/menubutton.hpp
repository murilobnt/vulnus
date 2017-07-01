#ifndef _MENUBUTTON_HPP_
#define _MENUBUTTON_HPP_

#include <SFML/Graphics.hpp>

class MenuButton {
private:
	sf::Sprite sprite;
	bool focused;

	// The boundaries of the animation
	int spriteInitX;
	int spriteEndX;
	int spriteInitY;
	int spriteEndY;

public:
	MenuButton(sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY);
	void setFocused(bool focused);
	bool isFocused();
};

#endif