#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string n)
{
	std::cout << "FragTrap constructor is called" << std::endl;
	FragTrap::Name = n;
	FragTrap::HitPoint = 100;
	FragTrap::EnergyPoint = 100;
	FragTrap::AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &F)
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = F;
}

FragTrap &FragTrap::operator = (const FragTrap &F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F)
		Name = F.Name;
		HitPoint = F.HitPoint;
		EnergyPoint = F.EnergyPoint;
		AttackDamage = F.AttackDamage;
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << Name << " attacks " << target
		<< ", causing " << AttackDamage << " hit points." << std::endl;
	EnergyPoint -= 1;
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << Name << " has taken " << amount << " damage." << std::endl;
	HitPoint -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap " << Name << " has repaired itself, gaining " << amount << " hit points." << std::endl;
	HitPoint += amount;
	EnergyPoint -= 1;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap wants to high five" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor is called" << std::endl;
}
