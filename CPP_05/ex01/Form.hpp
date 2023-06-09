#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;

class Form
{
	public:
		Form(string Name, int SignGrade, int ExecGrade); // assign
		Form(const Form &F);			// copy constructor
		Form &operator=(const Form &F); // copy assignment operator overload
		~Form();								// destructor
		string GetName();
		bool GetSign();
		int GetSignGrade();
		int GetExecGrade();
		friend std::ostream &operator<<(std::ostream &out, const Form &F);
		void beSigned(Bureaucrat &B);

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Form Grade Too High";
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Form Grade Too Low";
			}
		};
		class IsSignedException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Form is Signed";
			}
		};
	private:
		string	const Name;
		bool	Sign; // 1 = true; 0 = false
		int	const	Sign_Grade;
		int	const	Exec_Grade;
};

#endif