#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::string en = "enemy";
	ClapTrap C("Clap");
	ScavTrap S("Scav");
	FragTrap F("Frag");

	S.attack("Frag");
	F.takeDamage(20);
	F.beRepaired(5);
	C.attack("Scav");
	C.beRepaired(5);
	F.attack("Scav");
	S.takeDamage(30);
	S.beRepaired(5);
}