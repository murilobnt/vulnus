#include "blade.hpp"

Blade::Blade(float damage) : Weapon::Weapon(damage, SLASH){

}

void Blade::use(AliveEntity& player){

}

void Blade::update(){

}

bool Blade::isCollidingWithEnemy(const AliveEntity& enemy){
	return false;
}

bool Blade::isCollidingWithEnvironment(const TileGrid& grid){
	return false;
}

void Blade::draw(sf::RenderTarget& target){
	
}