#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	num;
	static const int fracbits = 8;
public:
	Fixed(void); //default constructor
	Fixed(const int); //constructor
	Fixed(const float); //constructor
	Fixed(const Fixed &F); //copy constructor
	Fixed &operator = (const Fixed &F); //copy assignment operator overload
	~Fixed(); // destructor
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator << (std::ostream &os, const Fixed &F);

#endif