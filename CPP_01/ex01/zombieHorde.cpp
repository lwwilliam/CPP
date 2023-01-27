#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	std::stringstream s;

	Zombie *newZombie = new Zombie[N];
	for (int x = 0; x < N; x++)
	{
		s.str("");
		s << x;
		newZombie[x].name_assign(name + " " + s.str());
	}
	return(newZombie);
}
