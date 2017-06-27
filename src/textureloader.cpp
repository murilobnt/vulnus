#include "textureloader.hpp"

#include <string>

void TextureLoader::loadTexture(std::string pathToImage){
	if (!this->texture.loadFromFile(pathToImage))
    {
        // error
    }
}

void TextureLoader::createTexture(int w, int h){
	if (!this->texture.create(w, h))
    {
        // error
    }
}

TextureLoader::TextureLoader(std::string pathToImage, int w, int h, bool isRepeated, bool hasBitmask){
	if(!hasBitmask){
		loadTexture(pathToImage);
	} else {
		Collision::CreateTextureAndBitmask(texture, pathToImage);
	}
	createTexture(w, h);
	this->texture.setRepeated(isRepeated);
}



sf::Texture& TextureLoader::getTexture(){
	return this->texture;
}
