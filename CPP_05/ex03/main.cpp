#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	sectionTitle(const std::string& title) {
	cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

void	testForm(Bureaucrat const &bureaucrat, AForm& form) 
{
	cout << form;
	form.beSigned(bureaucrat);
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
	cout << form;
}

int	main() {
	Bureaucrat	B1("B1", 1);
	Bureaucrat	B42("B42", 42);
	cout << B1 << B42;

	try {
		{
			sectionTitle("shrubbery creation");
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("shrubbery creation", "S");
			testForm(B1, *rrf);
			delete(rrf);
		}
		{
			sectionTitle("robotomy creation");
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "R");
			testForm(B1, *rrf);
			delete(rrf);
		}
		{
			sectionTitle("presidential pardon");
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("presidential pardon", "P");
			testForm(B1, *rrf);
			delete(rrf);
		}
		PresidentialPardonForm form("Deez");
		{
			sectionTitle("too low to execute");
			B1.signForm(form);
			B42.executeForm(form);
		}
	}
	catch (std::exception& e)
	{
		cout << "Error: " << e.what() << std::endl;
	}
	cout << endl;
}