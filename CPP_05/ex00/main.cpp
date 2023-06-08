#include "Bureaucrat.hpp"

int main (void)
{
	try
	{
		Bureaucrat B("B1", 100);
		cout << B;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << "\n\nToo High Test" << endl;
	try
	{
		Bureaucrat B("High", 999);
		cout << B;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << "\n\nToo Low Test" << endl;
	try
	{
		Bureaucrat B("Low", 0);
		cout << B;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
	return (0);
}