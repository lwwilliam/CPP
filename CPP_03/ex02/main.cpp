#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::string en = "enemy";
	ClapTrap C("ob1");
	ScavTrap S("ob2");
	FragTrap F("ob3");

	S.attack("ob3");
	F.takeDamage(20);
	F.beRepaired(5);
	C.attack("ob2");
	C.beRepaired(5);
	F.attack("ob2");
	S.takeDamage(30);
	S.beRepaired(5);
}