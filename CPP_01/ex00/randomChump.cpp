#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie r_zomb(name);
	r_zomb.name_assign(name);
	r_zomb.announce();
}