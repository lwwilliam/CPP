#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	cout << "Robotomy Constructor called" << endl;
	
}

RobotomyRequestForm::RobotomyRequestForm(string Target) : AForm("RobotomyRequestForm", 72, 45)
{
	cout << "Robotomy Target Constructor called" << endl;
	this->Target = Target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "R Destructor is called" << endl;
}

string RobotomyRequestForm::GetTarget()
{
	return(this->Target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->GetSign() == 0)
	{
		throw AForm::IsNotSignedException();
	}
	if (this->GetExecGrade() < executor.GetGrade())
	{
		throw Bureaucrat::GradeTooLowException();
	}
	cout << "zzzzzrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr, ";
	cout << "robotomy success rate is 50%!" << endl;
	if (std::rand() % 2 == 1)
		cout << this->Target << " has beem robotomized." << endl;
	else
		cout << this->Target << " robotomy failed." << endl;

}



