#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class AForm;
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

class Bureaucrat
{
	public:
		Bureaucrat();								//default constructor
		Bureaucrat(string name, int grade);			//assign	
		Bureaucrat(const Bureaucrat &B);			// copy constructor
		Bureaucrat &operator=(const Bureaucrat &B); // copy assignment operator overload
		~Bureaucrat();								// destructor
		string GetName();
		int GetGrade() const;
		void GradeIncrement();
		void GradeDecremennt();
		friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &B);
		void signForm(AForm const &F) const;
		void executeForm(AForm const & form) const;

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
		string const Name;
		int Grade;
};

#endif