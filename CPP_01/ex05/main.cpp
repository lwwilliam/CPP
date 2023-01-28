#include "Harl.hpp"

int main(void)
{
	Harl h;
	std::string input;
	std::cout << "Enter an argument" << std::endl;
	std::cout << "1. DEBUG" << std::endl;
	std::cout << "2. INFO" << std::endl;
	std::cout << "3. WARNING" << std::endl;
	std::cout << "4. ERROR\n" << std::endl;
	std::cin >> input;
	h.complain(input);
	return(0);
}