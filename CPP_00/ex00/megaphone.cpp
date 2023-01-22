#include<iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int x = 1; av[x]; x++)
	{
		for (int y = 0; av[x][y]; y++)
			std::cout << (char)(toupper(av[x][y]));
	}
	std::cout << std::endl;
	return(0);
}