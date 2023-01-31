#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	num = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	num = n * (1 << fracbits);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	num = roundf(n * (1 << fracbits));
}

Fixed::Fixed(const Fixed &F)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = F;
}

Fixed &Fixed::operator = (const Fixed &F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F)
		num = F.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


std::ostream &operator << (std::ostream &os, const Fixed &F)
{
	os << F.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (num);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	num = raw;
}

float Fixed::toFloat(void) const
{	
	return ((float)num / (float)(1 << fracbits));
}

int Fixed::toInt(void) const
{
	return ((int)num / (1 << fracbits));
}