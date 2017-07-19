#include "structures/inputhandler.hpp"

void InputHandler::handlePlayerInput(Player* player, sf::Keyboard::Key key, bool release){
	switch (key) {
		case sf::Keyboard::LShift:
			player->run(release);
		break;
		case sf::Keyboard::K:
			player->shoot(release);
		break;
		case sf::Keyboard::W:
		case sf::Keyboard::Up:
		case sf::Keyboard::Space:
			if(release){
				player->stopJump();
			} else {
				player->jump();
			}
		break;
		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			player->rightMovementControl(release);
		break;
		case sf::Keyboard::A:
		case sf::Keyboard::Left:
			player->leftMovementControl(release);
		break;
		case sf::Keyboard::Q:
		case sf::Keyboard::E:
			if(release)
			player->changeWeapon();
		break;
	}
}

void InputHandler::handleMouseInput(Player* player, sf::Vector2f mousePosition){
	int mouseX = mousePosition.x;
	int mouseY = mousePosition.y;
	player->teleport(mouseX, mouseY);
}