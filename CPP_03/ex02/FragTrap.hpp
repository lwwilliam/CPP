#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string n);
		FragTrap(const FragTrap &F);
		FragTrap &operator = (const FragTrap &F);
		void highFivesGuys(void);
		void attack(const std::string &target);
		// void takeDamage(unsigned int amount);
		// void beRepaired(unsigned int amount);
		~FragTrap();
};

#endif