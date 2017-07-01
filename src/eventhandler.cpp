#include "eventhandler.hpp"

EventHandler::EventHandler(Player* player, Cutscene* cutscene) : 
player(player),
cutscene(cutscene)
{ }

InputHandler EventHandler::getInputHandler() const{
	return this->inputhandler;
}

bool EventHandler::handleEvent(sf::Event event){
	switch(event.type){
		case sf::Event::KeyPressed :
			if(!this->cutscene->isActive()){
				this->inputhandler.handlePlayerInput(player, event.key.code, false);
			} else {
				cutscene->proceedCutscene(event.key.code, true);
			}
			return false;
		break;

		case sf::Event::KeyReleased :
			if(this->cutscene->isActive()){
				cutscene->proceedCutscene(event.key.code, false);
			} else {
				this->inputhandler.handlePlayerInput(player, event.key.code, true);
			}
			return false;
		break;

		default:
			return true;
		break;
	}
}

void EventHandler::handleMouseEvent(sf::Event event, sf::RenderWindow& screen){
	switch(event.type){
		case sf::Event::MouseButtonPressed :
			if(!this->cutscene->isActive()){
				this->inputhandler.handleMouseInput(player, screen.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)));
			}
		break;
	}
}