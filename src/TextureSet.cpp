#include "TextureSet.h"

#include <string>

void TextureSet::loadTexture(std::string pathToImage){
	if (!this->texture.loadFromFile(pathToImage))
    {
        // error
    }
}

void TextureSet::createTexture(int w, int h){
	if (!this->texture.create(w, h))
    {
        // error
    }
}

TextureSet::TextureSet(std::string pathToImage, int w, int h){
	loadTexture(pathToImage);
	createTexture(w, h);
}

sf::Texture* TextureSet::getTexture(){
	return &this->texture;
}
