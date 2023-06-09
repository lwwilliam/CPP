#include "Form.hpp"

Form::Form(string Name, int SignGrade, int ExecGrade) : Name(Name), Sign_Grade(SignGrade), Exec_Grade(ExecGrade)
{
	this->Sign = 0;
	cout << "Form Constructor is called" << endl;
	if (SignGrade < 1 || ExecGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (SignGrade > 150 || ExecGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &B) : Name(B.Name), Sign_Grade(B.Sign_Grade), Exec_Grade(B.Exec_Grade)
{
	std::cout << "F Copy constructor called" << std::endl;
	*this = B;
}

Form &Form::operator = (const Form &F)
{
	std::cout << "F Copy assignment operator called" << std::endl;
	if (this != &F)
	{
		Sign = F.Sign;
	}
	return (*this);
}

Form::~Form()
{
	cout << "Form Destructor is called" << endl;
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
	out << "Form Name: " << F.Name;
	if (F.Sign == 1)
		out  << "; Signed?: True";
	else
		out  << "; Signed?: False";
	out << "; Sign Grade: " << F.Sign_Grade;
	out << "; Execution Grade: " << F.Exec_Grade << endl;
	return (out);
}

void Form::beSigned(Bureaucrat &B)
{
	if (this->Sign == 1)
	{
		throw Form::IsSignedException();
	}
	if (this->Sign_Grade < B.GetGrade())
	{
		throw Form::GradeTooLowException();
	}
	else
		this->Sign = 1;
}
