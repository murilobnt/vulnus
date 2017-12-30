#include "entities/gamecomponents/npc.hpp"

NPC::NPC(int x, int y, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, int animInitX, int animEndX, int animInitY, int animEndY) : 
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH),
AnimatedEntity::AnimatedEntity(animInitX, animEndX, animInitY, animEndY){
	this->conversationState = 0;
}
