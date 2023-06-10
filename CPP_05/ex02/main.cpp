#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	sectionTitle(const std::string& title) {
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

void	testForm(Bureaucrat const &bureaucrat, AForm& form) {
	std::cout << form;
	form.beSigned(bureaucrat);
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
	std::cout << form;
}

int	main() {
	Bureaucrat	B1("B1", 1);
	Bureaucrat	B42("B42", 42);
	std::cout << B1 << B42;

	try {
		{
			sectionTitle("shrubbery creation");
			ShrubberyCreationForm form("Shrub");
			testForm(B1, form);
		}
		{
			sectionTitle("robotomy request");
			RobotomyRequestForm form("Robobo");
			testForm(B1, form);
		}
		{
			sectionTitle("presidential pardon");
			PresidentialPardonForm form("President");
			testForm(B1, form);
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
		std::cout << "Error: " << e.what() << std::endl;
	}
	cout << endl;
}