#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombs;

	randomChump("Test");
	zombs = newZombie("Name");
	zombs->announce();
	delete(zombs);
}