#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string Name;
		int HitPoint;
		int EnergyPoint;
		int AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string n);
		ClapTrap(const ClapTrap &C);
		ClapTrap &operator = (const ClapTrap &C);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();
};

#endif