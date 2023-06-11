#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			ScalarConverter sc(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
