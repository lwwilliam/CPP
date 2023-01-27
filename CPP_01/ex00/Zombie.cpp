#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Contructor is called" << std::endl;
}

Zombie::Zombie(std::string x)
{
	std::cout << x << ": Zombie Created" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::name_assign(std::string x)
{
	name = x;
}

Zombie::~Zombie()
{
	std::cout << name << ": Zombie Destroyed" << std::endl;
}