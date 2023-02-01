#include "ScavTrap.hpp"

int main()
{
	std::string en = "enemy";
	ScavTrap S("ob1");
	ClapTrap C("ob2");

	S.attack("ob2");
	C.takeDamage(5);
	C.attack("ob1");
	S.guardgate();
	C.beRepaired(2);
}