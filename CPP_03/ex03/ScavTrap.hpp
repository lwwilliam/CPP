#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string n);
		ScavTrap(const ScavTrap &S);
		ScavTrap &operator = (const ScavTrap &S);
		void guardgate();
		void attack(const std::string &target);
		// void takeDamage(unsigned int amount);
		// void beRepaired(unsigned int amount);
		~ScavTrap();
};

#endif