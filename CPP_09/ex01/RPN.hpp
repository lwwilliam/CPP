#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stack>

using std::cout;
using std::endl;
using std::string;

class RPN
{
private:
	std::stack<int> stack;

public:
	RPN(string &exp);
	RPN(const RPN &R);
	RPN &operator=(const RPN &R);
	void plus(int a, int b);
	void minus(int a, int b);
	void multiply(int a, int b);
	void divide(int a, int b);
	~RPN();
	class Error : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error!";
		}
	};
};
