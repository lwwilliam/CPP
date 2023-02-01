#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string n);
		ScavTrap(const ScavTrap &S);
		ScavTrap &operator = (const ScavTrap &S);
		void guardgate();
		void attack(const std::string &target);
		~ScavTrap();
};

#endif