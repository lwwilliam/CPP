#pragma once

#include <iostream>
#include <vector>

class NoOccurrence : public std::exception
{
	virtual const char *what() const throw()
	{
		return "No occurrence is found!!";
	}
};

template <typename T>
typename T::iterator easyfind(T &param1, int param2)
{
	typename T::iterator x;
	for (x = param1.begin(); x != param1.end(); x++)
	{
		if (*x == param2)
			return (x);
	}
	throw NoOccurrence();
	return typename T::iterator();
}