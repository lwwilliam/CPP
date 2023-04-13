#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::string en = "enemy";
	ClapTrap C("Clap");
	ScavTrap S("Scav");
	FragTrap F("Frag");
	DiamondTrap D("Diam");

	S.attack("Frag");
	S.attack("Diam");
	D.takeDamage(30);
	D.attack(en);
	D.beRepaired(2);
	F.takeDamage(20);
	F.beRepaired(5);
	C.attack("Scav");
	C.beRepaired(5);
	F.attack("Scav");
	S.takeDamage(30);
	S.beRepaired(5);
	D.whoAmI();
}