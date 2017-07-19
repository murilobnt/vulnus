#include "scenes/menuscene.hpp"

MenuScene::MenuScene(TextureManager& textureManager, SSceneManager* sceneManager) :
Scene::Scene(sceneManager),
player(100.f, 2, textureManager.getTexture(AET), 32, 32, 32, 32, 0.2, 0, 32, 0, 32),
startGame(0, 225, textureManager.getTexture(BUTTON), 0, 0, 250, 35),
loadGame(0, 300, textureManager.getTexture(BUTTON), 0, 0, 250, 35),
exit(0, 375, textureManager.getTexture(BUTTON), 0, 0, 250, 35)
{
	background.setTexture(textureManager.getTexture(MBG));
	background.setTextureRect(sf::IntRect(0, 0, 800, 600));

	player.setSpritePosition(600, 440);

	buttonArray[0] = &startGame;
	buttonArray[1] = &loadGame;
	buttonArray[2] = &exit;

	selected = 0;

	font.loadFromFile("fonts/Muli/Muli-Bold.ttf");

	startGame.initText(font, "Start");
	loadGame.initText(font, "Load Game");
	exit.initText(font, "Exit");

	hasCamera = false;

	buttonArray[selected]->setFocused(true);
}

void MenuScene::start(){

}

void MenuScene::handleEvent(sf::Event event, sf::RenderWindow& screen){
	switch(event.type){
		case sf::Event::KeyReleased :
			switch(event.key.code){
				case sf::Keyboard::Z:
				case sf::Keyboard::X:
				case sf::Keyboard::Return:
				case sf::Keyboard::Space:
					switch(selected){
						case 0:
							changeScene(GAME);
						break;
						case 1:
						break;
						case 2:
							screen.close();
						break;
					}
				break;
				case sf::Keyboard::Up:
					buttonArray[selected--]->setFocused(false);
					if(selected < 0)
						selected = 2;
					buttonArray[selected]->setFocused(true);
				break;
				case sf::Keyboard::Down:
					buttonArray[selected++]->setFocused(false);
					if(selected > 2)
						selected = 0;
					buttonArray[selected]->setFocused(true);
				break;
			}
		break;
	}
}

void MenuScene::controlCamera(sf::RenderWindow& window){

}

void MenuScene::doOperations(){	
	// Something like a background animation
	if(player.getSpritePosition().y >= 440){
		player.setMovementY(0.f);
		player.setIsJumping(false);
	}
	player.voidJump();
	player.movePlayer();
	player.moveEntity();
	player.applyGravity();
}

void MenuScene::drawEntities(sf::RenderWindow& window){
	window.draw(background);
	window.draw(player.getSprite());
	window.draw(startGame.getSprite());
	window.draw(startGame.getButtonLabel());
	window.draw(loadGame.getSprite());
	window.draw(loadGame.getButtonLabel());
	window.draw(exit.getSprite());
	window.draw(exit.getButtonLabel());
}

void MenuScene::MenuScene::doInternalTimedActions(){

}

void MenuScene::resetTimeHandlers(ClockHandler& clockHandler){
	
}

void MenuScene::changeScene(SceneCatalog sceneCatalog){
	getSSceneManager()->changeScene(sceneCatalog);
}