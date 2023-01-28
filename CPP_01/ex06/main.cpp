#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl h;
		std::string args(av[1]);
		h.complain(args);
	}
	else
	{
		std::cout << "Enter an argument" << std::endl;
		std::cout << "1. DEBUG" << std::endl;
		std::cout << "2. INFO" << std::endl;
		std::cout << "3. WARNING" << std::endl;
		std::cout << "4. ERROR" << std::endl;
	}
	return(0);
}