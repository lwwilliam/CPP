#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string n);
		void	attack(void);
		void	setWeapon(Weapon &weapon);
		~HumanB();
	private:
		std::string Name;
		Weapon *weapon;
};

#endif
