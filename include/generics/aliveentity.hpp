#ifndef _ALIVEENTITY_HPP_
#define _ALIVEENTITY_HPP_

// # External
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// # Internal
#include "structures/dynamicgrid.hpp"
#include "structures/inttostring.hpp"
#include "entities/clock/generictimehandler.hpp"
#include "generics/spritedentity.hpp"
#include "generics/animatedentity.hpp"

class AliveEntity : public SpritedEntity, public AnimatedEntity {
private:
	// The entityGravity of the entity
	float entityGravity;

	// The framerate of the animation
	sf::Time spriteAnimationFramerate;

	bool onCombo;

	GenericTimeHandler entityComboDelimeter;

	sf::Text damageOutput;

protected:
	float comboDamage;

	int quad;

	// The sprite of the entity
	//sf::Sprite sprite;

	// The movement of the entity
	sf::Vector2f movement;

	// Flag to check if the entity is jumping
	bool isJumping;

	bool doubleJump;

	// The integer to control the loop of the animation of the entity when it's walking right
	int animationRightLoop;

	// The integer to control the loop of the animation of the entity when it's walking left
	int animationLeftLoop;

	// Check the orientation of the entity
	bool facingRight;

	float maxHealth;

	// The total health
	float health;

	// The speed
	float speed;

	// The default speed of the entity
	float originalSpeed;

	// Recover player health
	void increaseHealth(float modifier);

	// Increase player speed
	void increaseSpeed(float modifier);

	// Decrease player health
	void decreaseHealth(float modifier);

	// Decrease player speed
	void decreaseSpeed(float modifier);

	void setComboDelimeter(int seconds);

public:

	/**
	 * Constructor.
	 * @param x the x position of the entity
	 * @param y the x position of the entity
	 * @param texture the texture for the entity
	 * @param spriteX the x position of the sprite
	 * @param spriteY the y position of the sprite
	 * @param spriteW the width of the sprite
	 * @param spriteH the height of the sprite
	 * @param entityGravity the entityGravity for the entity
	 */
	AliveEntity(int x, int y, float health, float speed, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float entityGravity, int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY);

	void moveEntity();
	
	void moveEntity(const DynamicGrid& dynaGrid);

	/**
	 * Get the movement of this entity.
	 * @return the movement of the entity
	 */
	sf::Vector2f getMovement() const;

	/**
	 * Set the movement of the entity on the X axis.
	 * @param x new movement in X axis
	 */
	void setMovementX(float x);

	/**
	 * Set the movement of the entity on the Y axis.
	 * @param y new movement in Y axis
	 */
	void setMovementY(float x);

	/**
	 * Apply the entityGravity on entity.
	 */
	void applyGravity();

	/**
	 * Set the animation framerate.
	 * @param fps the animation framerate
	 */
	void setAnimationFramerate(float fps);

	/**
	 * Check if the player is jumping or not.
	 * @return if the player is jumping or not
	 */
	bool getIsJumping() const;

	/**
	 * Set the verifier to the jump of the player.
	 * @param jumping the new state of the jumping verifier
	 */
	void setIsJumping(bool jumping);

	/**
	 * Get the total entityGravity of the entity.
	 * @return the total entityGravity of the entity
	 */
	float getGravity() const;

	float getMaxHealth() const;

	float getHealth() const;

	void updateQuad(int newQuad);

	void updateDamageText();

	sf::Text getDamageOutput() const;

	int getQuad() const;

	void cccomboBreak();

	bool getOnCombo() const;

	GenericTimeHandler* getEntityComboDelimeter();

	void init(const sf::Font& font);

	void drawText(sf::RenderTarget& target);

	bool isFacingRight() const;

	void setDoubleJump(bool doubleJump);
};

#endif
