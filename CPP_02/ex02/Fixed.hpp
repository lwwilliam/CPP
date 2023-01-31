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
	Fixed(const int); //int constructor
	Fixed(const float); //float constructor
	Fixed(const Fixed &F); //copy constructor
	Fixed &operator = (const Fixed &F); //copy assignment operator overload
	//arithmatic operator
	Fixed operator + (const Fixed &F);
	Fixed operator - (const Fixed &F);
	Fixed operator * (const Fixed &F);
	Fixed operator / (const Fixed &F);
	//comparison operator
	bool operator < (const Fixed &F) const;
	bool operator > (const Fixed &F) const;
	bool operator <= (const Fixed &F) const;
	bool operator >= (const Fixed &F) const;
	bool operator == (const Fixed &F) const;
	bool operator != (const Fixed &F) const;
	//increment operator
	Fixed operator ++(int);
	Fixed operator ++ ();

	Fixed operator --(int);
	Fixed operator -- ();


	~Fixed(); // destructor
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed min(Fixed &f1, Fixed &f2);
	static Fixed min(const Fixed &f1, const Fixed &f2);
	static Fixed max(Fixed &f1, Fixed &f2);
	static Fixed max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator << (std::ostream &os, const Fixed &F);

#endif