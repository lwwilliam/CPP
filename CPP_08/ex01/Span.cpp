#include "Span.hpp"

Span::Span(unsigned int num) : N(num), count(0)
{
	cout << "Constructing Span" << endl;
}

Span::Span(const Span &S)
{
	cout << "Copy constructor called" << endl;
	*this = S;
}

Span &Span::operator=(const Span &S)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &S)
	{
		this->N = S.N;
		this->count = S.count;
		this->C = S.C;
	}
	return (*this);
}

void Span::addNumber(int fill)
{
	if (count <= N)
	{
		C.push_back(fill);
		count++;
	}
	else
		throw Span::ElementAmountExceeded();
}

int Span::shortestSpan()
{
	if (count < 2)
	{
		throw Span::NotEnough();
	}
	std::sort(C.begin(), C.end());
	int span = C[1] - C[0];
	for (unsigned int i = 2; i < count; ++i)
	{
		int currSpan = C[i] - C[i - 1];
		if (currSpan < span)
		{
			span = currSpan;
		}
	}
	return (span);
}

int Span::longestSpan()
{
	if (count < 2)
	{
		throw Span::NotEnough();
	}
	// std::vector<int>::iterator x;
	// for (x = C.begin(); x != C.end(); x++)
	// 	cout << *x << endl;
	return (*(C.end() - 1) - *C.begin());
}

void Span::addArrNum(int *arr, int arr_len)
{
	if (arr_len + count <= N)
	{
		for (int x = 0; x < arr_len; x++)
		{
			C.push_back(arr[x]);
			count++;
		}
	}
	else
		throw Span::ElementAmountExceeded();
}

Span::~Span()
{
	cout << "Destructing Span" << endl;
}