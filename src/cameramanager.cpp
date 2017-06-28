#include "cameramanager.hpp"

GameSceneManager::GameSceneManager(sf::Texture& texture)
:
camera(0.f, 0.f, 320.f, 240.f, 2.0),
cutscene(0, texture, true)
{

}

void GameSceneManager::setCameraToPlayer(const Player& player, sf::Vector2u levelSize){
	camera.getToPlayer(player, levelSize);
}

void GameSceneManager::setCameraToWindow(sf::RenderWindow& window){
	window.setView(camera.getView());
}

void GameSceneManager::setSpritePositionRelativeToCamera(sf::Sprite& sprite, float xrule, float yrule){
	sprite.setPosition(sf::Vector2f(xrule, yrule));
}

float GameSceneManager::getCameraPointRelativeToCenterX(float offsetx){
	return camera.getView().getCenter().x + offsetx;
}

float GameSceneManager::getCameraPointRelativeToCenterY(float offsety){
	return camera.getView().getCenter().y + offsety;
}