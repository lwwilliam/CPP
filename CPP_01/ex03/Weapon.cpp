#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	setType(weapon);
}

void Weapon::setType(std::string type)
{
	WeaponType = type;
}

std::string Weapon::getType(void) const
{
	return(WeaponType);
}