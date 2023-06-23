#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			string arg(av[1]);
			RPN r(arg);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		cout << "Invalid argements : (./RPN <expression>)" << endl;
}