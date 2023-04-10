#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombs;

	randomChump("Chump1");
	zombs = newZombie("Name");
	zombs->announce();
	delete(zombs);
}