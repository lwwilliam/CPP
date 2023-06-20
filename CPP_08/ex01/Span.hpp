#pragma once

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Span
{
private:
	unsigned int N;
	unsigned int count;
	std::vector<int> C;

public:
	Span(unsigned int N);
	void addNumber(int fill);
	int shortestSpan();
	int longestSpan();
	~Span();
	class ElementAmountExceeded : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Element amount exceeded!";
		}
	};
};
