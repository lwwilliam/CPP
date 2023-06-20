#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

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
	Span(const Span &S);
	Span &operator=(const Span &S);
	void addNumber(int fill);
	int shortestSpan();
	int longestSpan();
	void addArrNum(int *arr, int arr_len);
	~Span();
	class ElementAmountExceeded : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Maximum number of elements reached!";
		}
	};
	class NotEnough : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Not enough numbers stored!";
		}
	};
};
