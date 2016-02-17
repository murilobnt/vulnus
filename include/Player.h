#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "AliveEntity.h"
#include "TextureSet.h"
#include <string>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player : public AliveEntity{
private:
	bool invulnerability;
	float health;
	float speed;
	float level;
	float desaccelerationX;
	bool movingRight;
	bool movingLeft;
	bool facingRight;
	bool bulletControl;
	std::vector<Bullet> theBullets;
	void increaseHealth(float modifier);
	void increaseSpeed(float modifier);
	void decreaseHealth(float modifier);
	void decreaseSpeed(float modifier);

public:
	Player(float health, float speed, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity);
	bool moving;
	void levelUp();
	void recieveDamage(float modifier);
	void recoveryHealth(float modifier);
	void movePlayer();
	void stopPlayer();
	void handlePlayerInput(sf::Keyboard::Key key, bool release);
	void handleMouseInput(sf::Vector2f mousePosition);
	void jump();
	void desacceleratePlayer();
	void applyPlayerAnimation(sf::Time* timeSinceLastUpdate);
	void checkHalfOne();
	void moveNDeleteBullets();
	std::vector<Bullet> getTheBullets();
	std::vector<Bullet>* getTheBulletsObject();
};

#endif
