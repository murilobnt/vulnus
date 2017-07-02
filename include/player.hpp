#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

// # External
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

// # Internal
#include "aliveentity.hpp"
#include "spritedentity.hpp"
#include "bullet.hpp"
#include "textureloader.hpp"
#include "polargun.hpp"
#include "blade.hpp"

class Player : public AliveEntity{
private:
	// Check if the player is invunerable
	bool invulnerability;

	// Check the movement of the player
	bool movingRight;
	bool movingLeft;

	// The control of the speed of the bullet button
	bool bulletControl;

	// The level
	float level;

	// The x desacceleration of the player
	float desaccelerationX;

	bool tryingToJump;

	void reactToDamage(float modifier);

	PolarGun ranged;
	Blade blade;

	int weaponId;

	GenericTimeHandler animation;
	GenericTimeHandler footstep;
	GenericTimeHandler invulnerabilityTime;
	GenericTimeHandler invulnerabilityAnimation;
public:
	/**
	 * Constructor.
	 * @param health the maximum health of the player
	 * @param speed the speed of the player
	 * @param texture the texture for player to find his sprite
	 * @param spriteX the x position of the initial sprite on texture image
	 * @param spriteY the y position of the initial sprite on texture image
	 * @param spriteW the width of the sprite
	 * @param spriteH the height of the sprite
	 * @param gravity the gravity for the player
	 */
	Player(float health, float speed, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY);

	// Check if the player is moving to any direction
	bool moving;

	/**
	 * Level up the player.
	 */
	void levelUp();

	/**
	 * Recieve damage.
	 * @param modifier the quantity of the damage
	 */
	void receiveDamage(float modifier);

	/**
	 * Recover health.
	 * @param modifier the quantity of the health to be recovered
	 */
	void recoveryHealth(float modifier);

	/**
	 * Move this player.
	 */
	void movePlayer();

	/**
	 * Stop this player.
	 */
	void stopPlayer();

	/**
	 * Get the mouse input of the player and threat it.
	 */

	void teleport(int mX, int mY);

	/**
	 * Jump.
	 */
	void jump();

	void stopJump();

	void handleMouseInput(sf::Vector2f mousePosition);

	void handlePlayerInput(sf::Keyboard::Key key, bool release);

	/**
	 * Run.
	 */
	void run(bool shouldRun);

	/**
	 * Desaccelerate the player.
	 */
	void desacceleratePlayer();

	void applyRightAnimation();

	void applyLeftAnimation();

	/**
	 * Animate the player according to certain framerate.
	 */
	void applyPlayerAnimation();

	void shoot(bool release);

	void rightMovementControl(bool release);

	void leftMovementControl(bool release);

	bool getInvulnerability() const;

	void setInvulnerability(bool invulnerability);

	Weapon& getPlayerWeapon();

	void changeWeapon();

	GenericTimeHandler& getTimeHandler(int index);
};

#endif
