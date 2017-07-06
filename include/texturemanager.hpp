#ifndef _TEXTUREMANAGER_HPP_
#define _TEXTUREMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "textureloader.hpp"
#include "textureindex.hpp"

class TextureManager {
private:
	TextureLoader aet;
	TextureLoader bg;
	TextureLoader cutscn;
	TextureLoader button;
	TextureLoader menubg;

public:
	TextureManager();
	sf::Texture& getTexture(TextureIndex index);
};

#endif