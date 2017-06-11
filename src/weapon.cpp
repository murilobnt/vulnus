#include "weapon.hpp"

Weapon::Weapon(float damage, WeaponTypes weaponType){
	this->damage = damage;
	this->weaponType = weaponType;
	this->active = false;
}

float Weapon::getDamage() const{
	return this->damage;
}

bool Weapon::isActive() const{
	return this->active;
}

WeaponTypes Weapon::getWeaponType() const{
	return this->weaponType;
}