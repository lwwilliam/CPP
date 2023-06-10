#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(string Target);
		~ShrubberyCreationForm();
		string GetTarget();
		void execute(Bureaucrat const & executor) const;
	private:
		string Target;
};
#endif