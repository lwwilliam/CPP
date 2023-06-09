#include "Bureaucrat.hpp"

int main (void)
{
	cout << "\n----------------" << endl;
	cout << "IN & DE crement Test" << endl;
	cout << "----------------" << endl;
	Bureaucrat Test("Test", 69);
	cout << Test;
	Test.GradeIncrement();
	cout << Test;
	Test.GradeDecremennt();
	cout << Test;
	cout << "\n----------------" << endl;
	cout << "Normal Test" << endl;
	cout << "----------------" << endl;
	try
	{
		Bureaucrat B("B1", 100);
		cout << B;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << "\n----------------" << endl;
	cout << "Too High Test" << endl;
	cout << "----------------" << endl;
	try
	{
		Bureaucrat B("High", 151);
		cout << B;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << "\n----------------" << endl;
	cout << "Too Low Test" << endl;
	cout << "----------------" << endl;
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

// int main(void)
// {
// 	Bureaucrat francis("Francis", 160);
// 	std::cout << francis << std::endl;
// 	francis.GradeIncrement();
// 	std::cout << francis << std::endl;
// 	francis.GradeDecremennt();
// 	std::cout << francis << std::endl;

// 	try
// 	{
// 		Bureaucrat jack("Jack", 0);
// 		std::cout << jack << std::endl;
// 	}
// 	catch(std::exception const &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		Bureaucrat jack("Jack", 1000);
// 		std::cout << jack << std::endl;
// 	}
// 	catch(std::exception const &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		Bureaucrat jack("Jack", 1);
// 		std::cout << jack << std::endl;
// 		jack.GradeIncrement();
// 		std::cout << jack << std::endl;
// 	}
// 	catch(std::exception const &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		Bureaucrat jack("Jack", 150);
// 		std::cout << jack << std::endl;
// 		jack.GradeDecremennt();
// 		std::cout << jack << std::endl;
// 	}
// 	catch(std::exception const &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return (0);
// }