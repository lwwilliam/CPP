#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	num = 0;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	num = n * (1 << fracbits);
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float constructor called" << std::endl;
	num = roundf(n * (1 << fracbits));
}

Fixed::Fixed(const Fixed &F)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = F;
}

Fixed &Fixed::operator = (const Fixed &F)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F)
		num = F.getRawBits();
	return (*this);
}

Fixed Fixed::operator + (const Fixed &F)
{
	// std::cout << "Arithmatic operator '+' called" << std::endl;
	float f1 = toFloat();
	float f2 = F.toFloat();
	return (f1 + f2);
}

Fixed Fixed::operator - (const Fixed &F)
{
	// std::cout << "Arithmatic operator '-' called" << std::endl;
	float f1 = toFloat();
	float f2 = F.toFloat();
	return (f1 - f2);
}

Fixed Fixed::operator * (const Fixed &F)
{
	// std::cout << "Arithmatic operator '*' called" << std::endl;
	float f1 = toFloat();
	float f2 = F.toFloat();
	return (f1 * f2);
}

Fixed Fixed::operator / (const Fixed &F)
{
	// std::cout << "Arithmatic operator '/' called" << std::endl;
	float f1 = toFloat();
	float f2 = F.toFloat();
	return (f1 / f2);
}

bool Fixed::operator < (const Fixed &F) const
{
	// std::cout << "Comparison operator '<' called" << std::endl;
	return (num < F.num);
}

bool Fixed::operator > (const Fixed &F) const
{
	// std::cout << "Comparison operator '>' called" << std::endl;
	return (num > F.num);
}

bool Fixed::operator <= (const Fixed &F) const
{
	// std::cout << "Comparison operator '<=' called" << std::endl;
	return (num <= F.num);
}

bool Fixed::operator >= (const Fixed &F) const
{
	// std::cout << "Comparison operator '>=' called" << std::endl;
	return (num >= F.num);
}

bool Fixed::operator == (const Fixed &F) const
{
	// std::cout << "Comparison operator '==' called" << std::endl;
	return (num == F.num);
}

bool Fixed::operator != (const Fixed &F) const
{
	// std::cout << "Comparison operator '!=' called" << std::endl;
	return (num != F.num);
}

Fixed Fixed::operator ++ (int)
{
	Fixed f(*this);
	++this->num;
	return (f);
}

Fixed Fixed::operator ++ ()
{
	++this->num;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed f(*this);
	--this->num;
	return (f);
}

Fixed Fixed::operator -- ()
{
	--this->num;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream &operator << (std::ostream &os, const Fixed &F)
{
	os << F.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (num);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

Fixed	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f2);
	return(f1);
}

Fixed	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f2);
	return(f1);
}

Fixed	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return(f1);
}

Fixed	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return(f1);
}
