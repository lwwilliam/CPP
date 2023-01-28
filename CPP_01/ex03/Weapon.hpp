#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string weapon);
		std::string getType() const;
		void setType(std::string type);
	private:
		std::string WeaponType;
};

#endif
