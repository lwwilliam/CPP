#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w): weapon(w) 
{
	Name = n;
	std::cout << "constructing HumanA" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Deconstucting HumanA" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << Name << " attacks with their " << weapon.getType() << std::endl;
}