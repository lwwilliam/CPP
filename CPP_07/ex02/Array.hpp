#pragma once
#include <iostream>

using	std::cout;
using	std::endl;

template <typename T>
class Array
{
	public:
		Array();							// Construction with no parameter
		Array(unsigned int n);				// Construction with an unsigned int n
		Array(const Array &A);				// copy constructor
		Array &operator=(const Array &A);	// copy assignment operator overload
		~Array();
		T &operator[](int);
		int	size();
		class OutOfBound : public std::exception
		{	
			virtual const char *what() const throw()
			{
				return "out of bound";
			}
		};
	private:
		T *arr;
		unsigned int len;
};
