#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			string arg(av[1]);
			PmergeMe P(arg);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		cout << "Invalid argements : (./RPN <num array>)" << endl;
}