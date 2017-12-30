#include "scenes/gamescenemanager.hpp"

GameSceneManager::GameSceneManager()
:
camera(0.f, 0.f, 683.f, 384.f, 2)
{

}

void GameSceneManager::resetCameraPosition(){
	camera.resetCameraPosition();
}

void GameSceneManager::setCameraToPlayer(const Player& player, sf::Vector2u levelSize){
	camera.getToPlayer(player, levelSize);
}

void GameSceneManager::setCameraToWindow(sf::RenderWindow& window){
	window.setView(camera.getView());
}

void GameSceneManager::setSpritePositionRelativeToCamera(sf::Transformable& sprite, float xrule, float yrule){
	//sprite.setPosition(sf::Vector2f(xrule, yrule));
	sprite.setPosition(sf::Vector2f(getCameraPointRelativeToCenterX(xrule), getCameraPointRelativeToCenterY(yrule)));
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