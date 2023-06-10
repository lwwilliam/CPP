#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	cout << "Default Constructor is called" << endl;
}

Bureaucrat::Bureaucrat(string name, int grade) : Name(name)
{
	cout << "Beureaucrat Constructor is called" << endl;
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
	cout << "Bureaucrat Destructor is called" << endl;
}

string Bureaucrat::GetName()
{
	return(this->Name);
}

int Bureaucrat::GetGrade() const
{
	return(this->Grade);
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

std::ostream & operator << (std::ostream &out, const Bureaucrat &B)
{
	out << B.Name;
	out << ", bureaucrat grade " << B.Grade << endl;
	return (out);
}

void Bureaucrat::signForm(AForm const &F) const
{
	if (F.GetSignGrade() > this->Grade)
		cout << this->Name << " signed " << F.GetName() << endl;
	else
	{
		cout << this->Name << " couldn't sign ";
		cout << F.GetName() << " because bureaucrat grade too low." << endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if (form.GetExecGrade() < this->Grade)
		cout << "Form is not executed due to " << this->Name << " grade too low." << endl;
	else
	{
		form.execute(*this);
		cout << this->Name << " executed " << form.GetName() << endl;
	}
}
