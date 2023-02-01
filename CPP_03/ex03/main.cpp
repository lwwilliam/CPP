#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::string en = "enemy";
	ClapTrap C("ob1");
	ScavTrap S("ob2");
	FragTrap F("ob3");
	DiamondTrap D("obj4");

	S.attack("ob3");
	S.attack("obj4");
	D.takeDamage(30);
	D.attack("teayufrkjae");
	D.beRepaired(2);
	F.takeDamage(20);
	F.beRepaired(5);
	C.attack("ob2");
	C.beRepaired(5);
	F.attack("ob2");
	S.takeDamage(30);
	S.beRepaired(5);
}