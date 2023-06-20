#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		cout << sp.shortestSpan() << endl;
		cout << sp.longestSpan() << endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		int num[] = {5, 7, 9, 6, 1, 4, 2};
		Span sp2 = Span(10);
		sp2.addNumber(3);
		sp2.addNumber(8);
		sp2.addNumber(0);
		sp2.addArrNum(num, 7);
		cout << sp2.shortestSpan() << endl;
		cout << sp2.longestSpan() << endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}