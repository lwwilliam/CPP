#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string n)
{
	Name = n;
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << Name << " attacks " << target
		<< ", causing " << AttackDamage << " hit points." << std::endl;
	EnergyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << Name << " has taken " << amount << " damage." << std::endl;
	HitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << Name << " has repaired itself, gaining " << amount << " hit points." << std::endl;
	HitPoint += amount;
	EnergyPoint -= 1;
}

ClapTrap::~ClapTrap()
{
	// std::cout << "End" << Name << HitPoint << " " << EnergyPoint << " " <<
	// 	AttackDamage << std::endl;		// for end res print
	std::cout << "Destructor is called" << std::endl;
}