#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default Constructor is called" << std::endl;
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string n)
{
	std::cout << "ClapTrap constructor is called" << std::endl;
	name = n;
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &C)
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = C;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &C)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &C)
		name = C.name;
		HitPoint = C.HitPoint;
		EnergyPoint = C.EnergyPoint;
		AttackDamage = C.AttackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << AttackDamage << " hit points." << std::endl;
	EnergyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has taken " << amount << " damage." << std::endl;
	HitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has repaired itself, gaining " << amount << " hit points." << std::endl;
	HitPoint += amount;
	EnergyPoint -= 1;
}

ClapTrap::~ClapTrap()
{
	std::cout << "End " << name  << " " << HitPoint << " " << EnergyPoint << " " <<
		AttackDamage << std::endl;		// for end res print
	std::cout << "ClapTrap destructor is called" << std::endl;
}