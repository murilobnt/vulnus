#include "weapon.hpp"

Weapon::Weapon(float damage, WeaponTypes weaponType){
	this->damage = damage;
	this->weaponType = weaponType;
	this->active = false;
}