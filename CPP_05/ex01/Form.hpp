#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
public:
	Form(string name, int grade);			// default constructor
	Form(const Form &F);			// copy constructor
	Form &operator=(const Form &F); // copy assignment operator overload
	~Form();								// destructor
	string GetName();
	bool GetSign();
	int GetSignGrade();
	int GetExecGrade();
	friend std::ostream &operator<<(std::ostream &out, const Form &F);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade Too High";
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Grade Too Low";
		}
	};
private:
	string	Name;
	bool	Sign;
	int		Sign_Grade;
	int		Exec_Grade;
};

#endif