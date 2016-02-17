#ifndef _ALIVEENTITY_H_
#define _ALIVEENTITY_H_

#include <string>
#include <SFML/Graphics.hpp>
#include "TextureSet.h"

class AliveEntity{
private:
	// The gravity of the entity
	float gravity;

	// The maximum gravity of the entity
	//float maximumGravity;

	// The framerate of the animation
	sf::Time animFps;

protected:
	// The sprite of the entity
	sf::Sprite sprite;

	// The movement of the entity
	sf::Vector2f movement;

	// Flag to check if the entity is jumping
	bool isJumping;

	// Flag to check if the entity wants to jump
	bool jumpWill;

	// The integer to control the loop of the animation of the entity when it's walking right
	int animationRightLoop;

	// The integer to control the loop of the animation of the entity when it's walking left
	int animationLeftLoop;

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

	void moveEntity(sf::Vector2f movement);

public:
	/**
	 * Get the sprite.
	 * @return this->sprite attribute
	 */
	sf::Sprite getSprite();

	/**
	 * Constructor.
	 * @param x the x position of the entity
	 * @param y the x position of the entity
	 * @param texture the texture for the entity
	 * @param spriteX the x position of the sprite
	 * @param spriteY the y position of the sprite
	 * @param spriteW the width of the sprite
	 * @param spriteH the height of the sprite
	 * @param gravity the gravity for the entity
	 */
	AliveEntity(int x, int y, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float gravity);

	/**
	 * Move this entity.
	 */
	void moveEntity();
	sf::Vector2f getMovement();
	void setMovementX(float x);
	void setMovementY(float x);
	void applyGravity();
	void changeSprite(bool right, bool left);
	void setAnimationFramerate(float fps);
	sf::Time getAnimationFramerate();
	bool getIsJumping();
	void setIsJumping(bool jumping);
	float getGravity();
	void setSpritePosition(float x, float y);
};

#endif
