#include "entities/item.hpp"

Item::Item(sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH) : 
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH){
	this->id = -1;
	this->modifier = 0;
	this->type = USELESS;
	this->name = "???";
	this->description = "???";
}

Item::Item(int id, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float modifier, ItemType type) : 
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH){
	this->id = id;
	this->modifier = modifier;
	this->type = type;
}

Item::Item(int id, std::string name, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float modifier, ItemType type) :
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH){
	this->id = id;
	this->modifier = modifier;
	this->type = type;
	this->name = name;
}

Item::Item(int id, std::string name, std::string description, sf::Texture const& texture, int spriteX, int spriteY, int spriteW, int spriteH, float modifier, ItemType type) :
SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH){
	this->id = id;
	this->modifier = modifier;
	this->type = type;
	this->name = name;
	this->description = description;
}

int Item::getId(){
	return this->id;
}

float Item::getModifier(){
	return this->modifier;
}

std::string Item::getName(){
	return this->name;
}

std::string Item::getDescription(){
	return this->description;
}

ItemType Item::getType(){
	return this->type;
}