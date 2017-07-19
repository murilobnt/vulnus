#include "structures/texturemanager.hpp"

TextureManager::TextureManager() :
aet("images/aliveentities.png", 128, 64, false, true),
bg("images/7536921_orig.png", 1000, 750, true),
cutscn("images/rcutscene.png", 416, 96),
button("images/uibutton.png", 250, 35),
menubg("images/7579418_altered.png", 800, 600)
{
}

sf::Texture& TextureManager::getTexture(TextureIndex index){
	switch(index){
		case AET:
			return this->aet.getTexture();
		break;
		case BG:
			return this->bg.getTexture();
		break;
		case CUTSCN:
			return this->cutscn.getTexture();
		break;
		case BUTTON:
			return this->button.getTexture();
		break;
		case MBG:
			return this->menubg.getTexture();
		break;
		default:
			return this->aet.getTexture();
		break;
	}
}