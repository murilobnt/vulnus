#ifndef _GAMESCENEMANAGER_HPP_
#define _GAMESCENEMANAGER_HPP_

#include <SFML/Graphics.hpp>

#include "camera.hpp"
#include "cutscene.hpp"

class GameSceneManager{
private:
	Camera camera;

public:
	GameSceneManager();

	void resetCameraPosition();
	void setCameraToPlayer(const Player& player, sf::Vector2u levelSize);
	void setCameraToWindow(sf::RenderWindow& window);
	void setSpritePositionRelativeToCamera(sf::Transformable& sprite, float xrule, float yrule);

	float getCameraPointRelativeToCenterX(float offsetx = 0.f);
	float getCameraPointRelativeToCenterY(float offsety = 0.f);
	sf::Vector2f getCameraSize();

	Camera getCamera();
};

#endif