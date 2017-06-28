#ifndef _GAMESCENEMANAGER_HPP_
#define _GAMESCENEMANAGER_HPP_

#include <SFML/Graphics.hpp>

#include "camera.hpp"
#include "cutscene.hpp"

class GameSceneManager{
private:
	Camera camera;
	Cutscene cutscene;

public:
	GameSceneManager(sf::Texture& texture);

	void setCameraToPlayer(const Player& player, sf::Vector2u levelSize);
	void setCameraToWindow(sf::RenderWindow& window);
	void setSpritePositionRelativeToCamera(sf::Sprite& sprite, float xrule, float yrule);

	float getCameraPointRelativeToCenterX(float offsetx = 0.f);
	float getCameraPointRelativeToCenterY(float offsety = 0.f);
};

#endif