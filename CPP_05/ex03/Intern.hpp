#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(); // default constructor
		Intern(const Intern &I); // copy constructor 
		Intern &operator = (const Intern &I); // copy assignment operator overload
		~Intern(); // destructor
		AForm *makeForm(string Name, string Target);
};
#endif