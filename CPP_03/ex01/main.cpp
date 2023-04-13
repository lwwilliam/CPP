#include "ScavTrap.hpp"

int main()
{
	std::string en = "enemy";
	ScavTrap S("Scav");
	ClapTrap C("Clap");

	S.attack("Clap");
	C.takeDamage(5);
	C.attack("Scav");
	S.guardgate();
	C.beRepaired(2);
}