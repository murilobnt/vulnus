#include "gamescenemanager.hpp"

GameSceneManager::GameSceneManager()
:
camera(0.f, 0.f, 400.f, 300.f, 2.0)
{

}

void GameSceneManager::setCameraToPlayer(const Player& player, sf::Vector2u levelSize){
	camera.getToPlayer(player, levelSize);
}

void GameSceneManager::setCameraToWindow(sf::RenderWindow& window){
	window.setView(camera.getView());
}

void GameSceneManager::setSpritePositionRelativeToCamera(sf::Transformable& sprite, float xrule, float yrule){
	sprite.setPosition(sf::Vector2f(xrule, yrule));
}

float GameSceneManager::getCameraPointRelativeToCenterX(float offsetx){
	return camera.getView().getCenter().x + offsetx;
}

float GameSceneManager::getCameraPointRelativeToCenterY(float offsety){
	return camera.getView().getCenter().y + offsety;
}

sf::Vector2f GameSceneManager::getCameraSize(){
	return camera.getView().getSize();
}

Camera GameSceneManager::getCamera(){
	return camera;
}