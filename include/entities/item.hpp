#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <string>

#include "generics/spritedentity.hpp"
#include "enums/itemtype.hpp"

class Item : public SpritedEntity {
private:
	int id;
	float modifier;

	std::string name;
	std::string description;

	ItemType type;

public:
	Item(sf::Texture const& texture, int spriteX, int spriteY, int spriteW = 32, int spriteH = 32);
	Item(int id, sf::Texture const& texture, int spriteX, int spriteY, int spriteW = 32, int spriteH = 32, float modifier = 0, ItemType type = USELESS);
	Item(int id, std::string name, sf::Texture const& texture, int spriteX, int spriteY, int spriteW = 32, int spriteH = 32, float modifier = 0, ItemType type = USELESS);
	Item(int id, std::string name, std::string description, sf::Texture const& texture, int spriteX, int spriteY, int spriteW = 32, int spriteH = 32, float modifier = 0, ItemType type = USELESS);

	int getId();
	float getModifier();

	std::string getName();
	std::string getDescription();

	ItemType getType();
};

#endif