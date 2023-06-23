#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			BitcoinExchange B(av[1]);
			// B.openFile();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		cout << "invalid arguments\n ./btc <filename>" << endl;
}