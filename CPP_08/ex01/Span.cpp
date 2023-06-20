#include "Span.hpp"

Span::Span(unsigned int num) : N(num), count(0)
{
	cout << "Constructing Span" << endl;
}

void Span::addNumber(int fill)
{
	if (count < N)
	{
		C.push_back(fill);
		count++;
	}
	else
		throw Span::ElementAmountExceeded();
}

int Span::shortestSpan()
{
	std::vector<int>::iterator x;

	std::sort(C.begin(), C.end());
	for (x = C.begin(); x != C.end(); x++)
	{
		cout << *x << " " << endl;
	}
}

Span::~Span()
{
	cout << "Destructing Span" << endl;
}