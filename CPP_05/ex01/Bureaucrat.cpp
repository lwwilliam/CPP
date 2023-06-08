#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(string name, int grade)
{
	cout << "constructor is called" << endl;
	this->Name = name;
	if (grade < 1)
	{
		// throw std::exception();
		throw Bureaucrat::GradeTooLowException();
		// grade = 150;
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooHighException();
		// grade = 150;
	}
	this->Grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &B)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = B;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &B)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &B)
	{
		Name = B.Name;
		Grade = B.Grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "destructor is called" << endl;
}

string Bureaucrat::GetName()
{
	return(this->Name);
}

int Bureaucrat::GetGrade()
{
	return(this->Grade);
}

std::ostream & operator << (std::ostream &out, const Bureaucrat &B)
{
	out << B.Name;
	out << ", bureaucrat grade " << B.Grade << endl;
	return (out);
}
