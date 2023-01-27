#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	newZombie->name_assign(name);
	return(newZombie);
}