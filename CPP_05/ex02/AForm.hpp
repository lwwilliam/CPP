#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Bureaucrat.hpp"
class Bureaucrat;

using std::cout;
using std::endl;
using std::string;

class AForm
{
	public:
		// AForm(); // default constructor
		AForm(string Name, int SignGrade, int ExecGrade); // assign
		AForm(const AForm &F);			// copy constructor
		AForm &operator=(const AForm &F); // copy assignment operator overload
		~AForm();								// destructor
		string GetName() const ;
		bool GetSign() const;
		int GetSignGrade() const;
		int GetExecGrade() const;
		friend std::ostream &operator<<(std::ostream &out, const AForm &F);
		void beSigned(Bureaucrat const &B);
		virtual void execute(Bureaucrat const & executor) const
		{
			(void)executor;
		}

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "AForm Grade Too High";
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "AForm Grade Too Low";
			}
		};
		class IsSignedException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "AForm is Signed";
			}
		};
		class IsNotSignedException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "AForm is not Signed";
			}
		};
	private:
		const string Name;
		bool	Sign; // 1 = true; 0 = false
		int	const	Sign_Grade;
		int	const	Exec_Grade;
};

#endif