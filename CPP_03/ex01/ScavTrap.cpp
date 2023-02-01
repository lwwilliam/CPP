#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string n)
{
	std::cout << "ScavTrap constructor is called" << std::endl;
	ScavTrap::Name = n;
	ScavTrap::HitPoint = 100;
	ScavTrap::EnergyPoint = 50;
	ScavTrap::AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &S)
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = S;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &S)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &S)
		Name = S.Name;
		HitPoint = S.HitPoint;
		EnergyPoint = S.EnergyPoint;
		AttackDamage = S.AttackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << Name << " attacks " << target
		<< ", causing " << AttackDamage << " hit points." << std::endl;
	EnergyPoint -= 1;
}

void ScavTrap::guardgate()
{
	std::cout << "ScavTrap is now in gatekeeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor is called" << std::endl;
}
