#include "menuscene.hpp"

MenuScene::MenuScene(TextureManager& textureManager, SSceneManager* sceneManager) :
Scene::Scene(sceneManager)
{
	hasCamera = false;
}

void MenuScene::start(){
	
}

void MenuScene::handleEvent(sf::Event event, sf::RenderWindow& screen){
	switch(event.type){
		case sf::Event::KeyReleased :
			switch(event.key.code){
				case sf::Keyboard::Z:
					changeScene();
				break;
			}
		break;
	}
}

void MenuScene::controlCamera(sf::RenderWindow& window){

}

void MenuScene::doOperations(){
	
}

void MenuScene::drawEntities(sf::RenderWindow& window){

}

void MenuScene::MenuScene::doInternalTimedActions(){

}

void MenuScene::resetTimeHandlers(ClockHandler& clockHandler){
	
}

void MenuScene::changeScene(){
	getSSceneManager()->changeScene();
}