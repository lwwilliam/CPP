#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	cout << "Shrubbery Constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string Target) : AForm("ShrubberyCreationForm", 145, 137)
{
	cout << "Shrubbery Target Constructor called" << endl;
	this->Target = Target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "S Destructor is called" << endl;
}

string ShrubberyCreationForm::GetTarget()
{
	return(this->Target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->GetSign() == 0)
	{
		throw AForm::IsNotSignedException();
	}
	if (this->GetExecGrade() < executor.GetGrade())
	{
		throw Bureaucrat::GradeTooLowException();
	}
	std::fstream fs;
	string filename = this->Target + "_shrubbery";
	const char * name = filename.c_str();
	fs.open (name , std::fstream::in | std::fstream::out | std::fstream::trunc);
	fs << "      /\\      " << endl;
	fs << "     /\\*\\     " << endl;
	fs << "    /\\O\\*\\    " << endl;
	fs << "   /*/\\/\\/\\   " << endl;
	fs << "  /\\O\\/\\*\\/\\  " << endl;
	fs << " /\\*\\/\\*\\/\\/\\ " << endl;
	fs << "/\\O\\/\\/*\\/O/\\\\"<< endl;
	fs << "      ||      " << endl;
	fs << "      ||      " << endl;
	fs << "      ||      " << endl;
	fs.close();
}
