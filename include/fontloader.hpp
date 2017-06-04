#ifndef _FONTLOADER_HPP_
#define _FONTLOADER_HPP_

#include <SFML/Graphics.hpp>
#include <string>

namespace FontLoader{
	sf::Font LoadFontFromFile(std::string Path);
};

#endif