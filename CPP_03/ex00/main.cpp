#include "ClapTrap.hpp"

int main()
{
	std::string en = "daygd";
	ClapTrap c("test");
	c.attack(en);
	c.takeDamage (3);
	c.beRepaired (1);
	c.takeDamage (3);
}