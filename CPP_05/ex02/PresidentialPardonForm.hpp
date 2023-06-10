#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(string Target);
		~PresidentialPardonForm();
		string GetTarget();
		void execute(Bureaucrat const & executor) const;
	private:
		string Target;
};
#endif