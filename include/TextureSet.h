#ifndef _TEXTURESET_H_
#define _TEXTURESET_H_

#include <SFML/Graphics.hpp>
#include <string>

class TextureSet{
private:
	sf::Texture texture;

	void loadTexture(std::string pathToImage);

	void createTexture(int w, int h);

public:

	TextureSet(std::string pathToImage, int w, int h);

	sf::Texture* getTexture();
};

#endif
