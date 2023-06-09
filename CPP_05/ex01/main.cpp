#include "Form.hpp"

int main (void)
{
	Bureaucrat Test1("Test 1", 40);
	try
	{
		Form F1("Form 1", 50, 50);
		cout << F1;
		cout << "Signing....." << endl;
		F1.beSigned(Test1);
		Test1.signForm(F1);
		cout << F1;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}

	cout << "\n----------------" << endl;
	cout << "Too Low Test" << endl;
	cout << "----------------" << endl;
	Bureaucrat Test2("Test 2", 100);
	try
	{
		Form F2("Form 2", 50, 50);
		cout << F2;
		cout << "Signing......" << endl;
		Test2.signForm(F2);
		F2.beSigned(Test2);
		cout << F2;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}

	cout << "\n----------------" << endl;
	cout << "Too High Test" << endl;
	cout << "----------------" << endl;
	Bureaucrat Test3("Test 3", 100);
	try
	{
		Form F3("Form 3", 0, 0);
		cout << F3;
		cout << "Signing......" << endl;
		Test3.signForm(F3);
		F3.beSigned(Test3);
		cout << F3;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}

	cout << "\n----------------" << endl;
	cout << "IN & DE crement Test" << endl;
	cout << "----------------" << endl;
	Bureaucrat Test4("Test 4", 50);
	cout << Test4;
	try
	{
		Form F4("Form 4", 50, 50);
		cout << F4;
		cout << "Signing......" << endl;
		F4.beSigned(Test4);
		Test4.signForm(F4);
		cout << F4;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << "\n----------------" << endl;
	cout << "Increment" << endl;
	cout << "----------------" << endl;
	Test4.GradeIncrement();
	cout << Test4;
	try
	{
		Form F5("Form 5", 50, 50);
		cout << F5;
		cout << "Signing......" << endl;
		F5.beSigned(Test4);
		Test4.signForm(F5);
		cout << F5;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << "\n----------------" << endl;
	cout << "Decrement" << endl;
	cout << "----------------" << endl;
	Test4.GradeDecremennt();
	Test4.GradeDecremennt();
	cout << Test4;
	try
	{
		Form F6("Form 6", 50, 50);
		cout << F6;
		cout << "Signing......" << endl;
		Test4.signForm(F6);
		F6.beSigned(Test4);
		cout << F6;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
	return(0);
}
