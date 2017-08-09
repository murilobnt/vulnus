#include "structures/playermousecontrol.hpp"

void PlayerMouseControl::controlEntityByMouse(sf::Event event, SpritedEntity& spritedEntity, sf::Vector2f mousePos){
	switch(event.type){
		case sf::Event::MouseButtonPressed :
			spritedEntity.setSpritePosition(mousePos);
		break;
	}
}