#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	std::cout << "a created\n" << std::endl;
	Fixed b( a );
	std::cout << "b created\n" << std::endl;
	Fixed c;
	std::cout << "c created\n" << std::endl;
	c = b;
	std::cout << "c copy\n" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
