#include "Files.hpp"

int main (int ac, char **av) 
{
	if (ac == 4)
	{
		Files f(av[1], av[2], av[3]);
		f.openfile();
	}
	else
		std::cout << "<filename> (string 1) (string 2)" << std::endl;
	return 0;
}

