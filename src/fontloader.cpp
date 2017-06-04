#include "fontloader.hpp"

sf::Font FontLoader::LoadFontFromFile(std::string Path){
	sf::Font font;
	font.loadFromFile(Path);
	return font;
}