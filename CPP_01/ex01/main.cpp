#include "Zombie.hpp"

int	main(void)
{
	int		nb;
	nb = 3;
	Zombie	*zombs = zombieHorde(nb , "Test");
	for (int x = 0; x < nb; x++)
		zombs[x].announce();
	delete[] zombs;
}