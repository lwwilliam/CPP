#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string n, Weapon &weapon); //w is weapon, n is name
		void	attack(void);
		~HumanA();
	private:
		Weapon &weapon;
		std::string Name;
};

#endif
