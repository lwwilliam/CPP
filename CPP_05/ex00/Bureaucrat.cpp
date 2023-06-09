#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(string const name, int grade) : Name(name)
{
	cout << "Constructor is called" << endl;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->Grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &B) : Name(B.Name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = B;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &B)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &B)
	{
		Grade = B.Grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "Destructor is called" << endl;
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

void Bureaucrat::GradeIncrement()
{
	this->Grade--;
	if (this->Grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::GradeDecremennt()
{
	this->Grade++;
	if (this->Grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}
