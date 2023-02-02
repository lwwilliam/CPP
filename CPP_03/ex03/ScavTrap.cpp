#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor is called" << std::endl;
	ScavTrap::HitPoint = 100;
	ScavTrap::EnergyPoint = 50;
	ScavTrap::AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string n)
{
	std::cout << "ScavTrap constructor is called" << std::endl;
	ScavTrap::name = n;
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
		name = S.name;
		HitPoint = S.HitPoint;
		EnergyPoint = S.EnergyPoint;
		AttackDamage = S.AttackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << AttackDamage << " hit points." << std::endl;
	EnergyPoint -= 1;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << name << " has taken " << amount << " damage." << std::endl;
	HitPoint -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << name << " has repaired itself, gaining " << amount << " hit points." << std::endl;
	HitPoint += amount;
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
