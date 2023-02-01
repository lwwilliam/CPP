#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::string en = "enemy";
	ScavTrap S("ob1");
	ClapTrap C("ob2");
	ScavTrap F(S);
	ClapTrap D(C);

	S.attack("ob2");
	C.takeDamage(5);
	D.attack(en);
	D.takeDamage(40);
	D.beRepaired(2);
	C.attack("ob1");
	S.guardgate();
	C.beRepaired(2);
	F.takeDamage(8);
	F.attack(en);
	F.takeDamage(20);
	F.attack(en);
	F.attack(en);
}