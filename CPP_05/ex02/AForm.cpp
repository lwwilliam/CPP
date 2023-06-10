#include "AForm.hpp"

// AForm::AForm() : Name("X"), Sign_Grade(150), Exec_Grade(150)
// {
// 	cout << "run" << endl;
// }

AForm::AForm(string Name, int SignGrade, int ExecGrade) : Name(Name), Sign_Grade(SignGrade), Exec_Grade(ExecGrade)
{
	this->Sign = 0;
	cout << "AForm Constructor is called " << this->Name << endl;
	if (SignGrade < 1 || ExecGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (SignGrade > 150 || ExecGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm &B) : Name(B.Name), Sign_Grade(B.Sign_Grade), Exec_Grade(B.Exec_Grade)
{
	std::cout << "F Copy constructor called" << std::endl;
	*this = B;
}

AForm &AForm::operator = (const AForm &F)
{
	std::cout << "F Copy assignment operator called" << std::endl;
	if (this != &F)
	{
		Sign = F.Sign;
	}
	return (*this);
}

AForm::~AForm()
{
	cout << "AForm Destructor is called " << this->Name << endl;
}

string AForm::GetName() const
{
	return(this->Name);
}

bool AForm::GetSign() const
{
	return (this->Sign);
}

int AForm::GetSignGrade() const
{
	return(this->Sign_Grade);
}

int AForm::GetExecGrade() const
{
	return(this->Exec_Grade);
}

std::ostream & operator << (std::ostream &out, const AForm &F)
{
	out << "AForm Name: " << F.Name;
	if (F.Sign == 1)
		out  << "; Signed?: True";
	else
		out  << "; Signed?: False";
	out << "; Sign Grade: " << F.Sign_Grade;
	out << "; Execution Grade: " << F.Exec_Grade << endl;
	return (out);
}

void AForm::beSigned(Bureaucrat const &B)
{
	if (this->Sign == 1)
	{
		throw AForm::IsSignedException();
	}
	if (this->Sign_Grade < B.GetGrade())
	{
		throw AForm::GradeTooLowException();
	}
	else
		this->Sign = 1;
}
