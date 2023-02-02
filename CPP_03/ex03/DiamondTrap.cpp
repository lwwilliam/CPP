#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string n) : ClapTrap( n ), FragTrap( n ), ScavTrap( n )
{
	name = n;
	ClapTrap::name = (n +  "_clap_name");
	HitPoint = FragTrap::HitPoint;
    EnergyPoint = ScavTrap::EnergyPoint;
    AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &D)
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = D;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &D)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &D)
		name = D.name;
		HitPoint = D.HitPoint;
		EnergyPoint = D.EnergyPoint;
		AttackDamage = D.AttackDamage;
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << "DiamondTrap " << name << " has taken " << amount << " damage." << std::endl;
	HitPoint -= amount;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	std::cout << "DiamondTrap " << name << " has repaired itself, gaining " << amount << " hit points." << std::endl;
	HitPoint += amount;
	EnergyPoint -= 1;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << ClapTrap::name << " " << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor is called" << std::endl;
}

