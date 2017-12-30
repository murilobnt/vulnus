#ifndef _NPC_HPP_
#define _NPC_HPP_

#include <SFML/Graphics.hpp>

#include "generics/animatedentity.hpp"
#include "generics/spritedentity.hpp"
#include "entities/gamecomponents/player.hpp"

class NPC : public SpritedEntity, public AnimatedEntity {
private:
	int conversationState;

public:
	NPC(int x, int y, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, int animInitX, int animEndX, int animInitY, int animEndY);
	virtual void interactWithPlayer(Player& player) = 0;
};

#endif