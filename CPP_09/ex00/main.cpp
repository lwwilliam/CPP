#include "BitcoinExchange.hpp"

int main()
{
	try
	{
		BitcoinExchange B("input.txt");
		// B.openFile();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}