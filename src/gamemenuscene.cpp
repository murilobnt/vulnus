#include "scenes/gamemenuscene.hpp"

GameMenuScene::GameMenuScene(TextureManager& textureManager, SSceneManager* sceneManager) :
Scene::Scene(sceneManager),
resume(0, 225, textureManager.getTexture(BUTTON), 0, 0, 250, 35),
exit(0, 300, textureManager.getTexture(BUTTON), 0, 0, 250, 35)
{
	background.setTexture(textureManager.getTexture(MBG));
	background.setTextureRect(sf::IntRect(0, 0, 800, 600));

	buttonArray[0] = &resume;
	buttonArray[1] = &exit;

	selected = 0;

	font.loadFromFile("fonts/Muli/Muli-Bold.ttf");

	resume.initText(font, "Resume");
	exit.initText(font, "Main Menu");

	hasCamera = false;

	buttonArray[selected]->setFocused(true);
}

void GameMenuScene::start(){

}

void GameMenuScene::handleEvent(sf::Event event, sf::RenderWindow& screen){
	switch(event.type){
		case sf::Event::KeyReleased :
			switch(event.key.code){
				case sf::Keyboard::Z:
				case sf::Keyboard::Return:
				case sf::Keyboard::Space:
					switch(selected){
						case 0:
							this->sceneManager->setLastScene();
						break;
						case 1:
							changeScene(MENU);
						break;
					}
				break;
				case sf::Keyboard::Escape:
					this->sceneManager->setLastScene();
				break;
				case sf::Keyboard::Up:
					buttonArray[selected--]->setFocused(false);
					if(selected < 0)
						selected = 2;
					buttonArray[selected]->setFocused(true);
				break;
				case sf::Keyboard::Down:
					buttonArray[selected++]->setFocused(false);
					if(selected > 1)
						selected = 0;
					buttonArray[selected]->setFocused(true);
				break;
			}
		break;
	}
}

void GameMenuScene::controlCamera(sf::RenderWindow& window){
	
}

void GameMenuScene::doOperations(){	
	// Something like a background animation
}

void GameMenuScene::drawEntities(sf::RenderWindow& window){
	window.draw(background);
	window.draw(resume.getSprite());
	window.draw(resume.getButtonLabel());
	window.draw(exit.getSprite());
	window.draw(exit.getButtonLabel());
}

void GameMenuScene::GameMenuScene::doInternalTimedActions(){

}

void GameMenuScene::resetTimeHandlers(ClockHandler& clockHandler){
	
}

void GameMenuScene::changeScene(SceneCatalog sceneCatalog){
	getSSceneManager()->changeScene(sceneCatalog);
}