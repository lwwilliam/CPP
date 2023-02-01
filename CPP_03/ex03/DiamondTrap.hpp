#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string n);
		DiamondTrap(const DiamondTrap &D);
		DiamondTrap &operator = (const DiamondTrap &D);
		void attack(const std::string &target);
		void takeDamage(unsigned int aount);
		void beRepaired(unsigned int amount);
		void whoAmI();
		~DiamondTrap();
	private:
		std::string name;
};

#endif