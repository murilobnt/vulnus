#include "structures/eventhandler.hpp"

void EventHandler::handleEvent(sf::Event event, ControlableEntity& entity){
	switch(event.type){
		case sf::Event::KeyPressed :
			entity.controlEntity(event.key.code, false);
		break;

		case sf::Event::KeyReleased :
			entity.controlEntity(event.key.code, true);
		break;
	}
}