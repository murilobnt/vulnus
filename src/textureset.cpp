#include "textureset.hpp"

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

TextureSet::TextureSet(std::string pathToImage, int w, int h, bool isRepeated){
	loadTexture(pathToImage);
	createTexture(w, h);
	this->texture.setRepeated(isRepeated);
}

sf::Texture* TextureSet::getTexture(){
	return &this->texture;
}