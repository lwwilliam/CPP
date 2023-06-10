#include "Intern.hpp"

Intern::Intern()
{
	cout << "Intern Constructor" << endl;
}

Intern::Intern(const Intern &I)
{
	cout << "Intern Copy constructor called" << endl;
	*this = I;
}

Intern &Intern::operator = (const Intern &I)
{
	std::cout << "Intern assignment operator called" << std::endl;
	if (this == &I)
		return (*this);
	return (*this);
}

Intern::~Intern()
{
	cout << "Intern Destructor" << endl;
}

AForm *RobotomyForm(string Target)
{
	return(new RobotomyRequestForm(Target));
}

AForm *ShrubberyForm(string Target)
{
	return(new ShrubberyCreationForm(Target));
}
	
AForm *PresidentialForm(string Target)
{
	return(new PresidentialPardonForm(Target));
}

AForm *Intern::makeForm(string Name, string Target)
{
	string type;
	int x = 0;
	AForm *(*funct[])(string Target) = 
	{&RobotomyForm, &ShrubberyForm, &PresidentialForm};
	std::string arr[] =
	{"robotomy request", "shrubbery creation", "presidential pardon"};
	for (int i = 0; i < (int)Name.size(); i++)
		type += tolower(Name[i]);
	while (x < 3 && arr[x].compare(type))
		x++;
	if(x < 4)
		return ((*funct[x++])(Target));
	else
		cout << Name << "is not created by Intern" << endl;
	return(NULL);
}