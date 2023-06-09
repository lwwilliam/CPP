#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Bureaucrat
{
public:
	Bureaucrat(string name, int grade);			// default constructor
	Bureaucrat(const Bureaucrat &B);			// copy constructor
	Bureaucrat &operator=(const Bureaucrat &B); // copy assignment operator overload
	~Bureaucrat();								// destructor
	string GetName();
	int GetGrade();
	friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &B);
	void GradeIncrement();
	void GradeDecremennt();

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