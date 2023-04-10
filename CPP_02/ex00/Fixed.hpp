#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int	num;
	public:
		Fixed(void); //default constructor
		Fixed(const Fixed &F); //copy constructor
		Fixed &operator = (const Fixed& F); //copy assignment operator overload
		~Fixed(); // destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif