#include "Form.hpp"

Form::Form(string name, int grade)
{
	cout << "constructor is called" << endl;
	this->Name = name;
	if (grade < 1)
	{
		throw Form::GradeTooLowException();
	}
	else if (grade > 150)
	{
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form &B)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = B;
}

Form &Form::operator = (const Form &F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F)
	{
		Name = F.Name;
		Sign = F.Sign;
		Sign_Grade = F.Sign_Grade;
		Exec_Grade = F.Exec_Grade;
	}
	return (*this);
}

Form::~Form()
{
	cout << "destructor is called" << endl;
}

string Form::GetName()
{
	return(this->Name);
}

bool Form::GetSign()
{
	return (this->Sign);
}

int Form::GetSignGrade()
{
	return(this->Sign_Grade);
}

int Form::GetExecGrade()
{
	return(this->Exec_Grade);
}

std::ostream & operator << (std::ostream &out, const Form &F)
{
	out << F.Name;
	out << ", Form grade " << endl;
	return (out);
}
