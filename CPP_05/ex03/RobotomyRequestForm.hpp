#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(string Target);
		~RobotomyRequestForm();
		string GetTarget();
		void execute(Bureaucrat const & executor) const;
	private:
		string Target;
};
#endif