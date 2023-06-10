#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	cout << "Presidential Constructor called" << endl;
	// AForm("PresidentialPardonForm", 25, 5)
}

PresidentialPardonForm::PresidentialPardonForm(string Target) : AForm("PresidentialPardonForm", 25, 5)
{
	cout << "Presidential Target Constructor called" << endl;
	this->Target = Target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "P Destructor is called" << endl;
}

string PresidentialPardonForm::GetTarget()
{
	return(this->Target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->GetSign() == 0)
	{
		throw AForm::IsNotSignedException();
	}
	if (this->GetExecGrade() < executor.GetGrade())
	{
		throw Bureaucrat::GradeTooLowException();
	}
	cout <<  this->Target << " has been pardoned by Zaphod Beeblebrox." << endl;
}


