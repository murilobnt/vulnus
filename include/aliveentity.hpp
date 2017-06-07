#ifndef _ALIVEENTITY_HPP_
#define _ALIVEENTITY_HPP_

// # External
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

// # Internal
#include "textureset.hpp"
#include "dynamicgrid.hpp"
#include "inttostring.hpp"
#include "generictimehandler.hpp"
#include "fontloader.hpp"

class AliveEntity{
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
	sf::Sprite sprite;

	// The movement of the entity
	sf::Vector2f movement;

	// Flag to check if the entity is jumping
	bool isJumping;

	// The integer to control the loop of the animation of the entity when it's walking right
	int animationRightLoop;

	// The integer to control the loop of the animation of the entity when it's walking left
	int animationLeftLoop;

	// The boundaries of the animation
	int spriteInitX;
	int spriteEndX;
	int spriteInitY;
	int spriteEndY;

	// Check the orientation of the entity
	bool facingRight;

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

	/**
	 * Set the sprite based on a texture.
	 * @param texture The texture
	 */
	void setSprite(sf::Texture const& texture);

	/**
	 * Set the rect of the sprite of the entity.
	 * @param x The x coordinate of the sprite on the texture
	 * @param y The y coordinate of the sprite on the texture
	 * @param w The width of the sprite
	 * @param h The height of the sprite
	 */
	void configureSpriteRect(int x, int y, int w, int h);

	/**
	 *
	 *
	 */
	void setSpritePosition(sf::Vector2f position);

	void setComboDelimeter(int seconds);

public:
	
	/**
	 * Get the sprite.
	 * @return this->sprite attribute
	 */
	sf::Sprite getSprite() const;

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

	/**
	 * Move this entity.
	 */
	void moveEntity();

	void moveEntity(DynamicGrid dynaGrid);

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

	/**
	 * Set the position of the sprite.
	 * @param x the new x position of the sprite
	 * @param y the new y position of the sprite
	 */
	void setSpritePosition(float x, float y);

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
};

#endif
