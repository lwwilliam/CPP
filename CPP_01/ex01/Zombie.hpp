#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <iomanip>
#include <sstream>

class Zombie
{
	private:
		std::string name;
	public:
		void	announce(void);
		void	name_assign(std::string x);
		Zombie(std::string x);
		Zombie();
		~Zombie();
};

Zombie *newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );


#endif