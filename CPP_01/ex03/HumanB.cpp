#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
	Name = n;
	std::cout << "constructing HumanB" << std::endl;

}

HumanB::~HumanB()
{
	std::cout << "Deconstucting HumanB" << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << Name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}