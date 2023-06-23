#include "RPN.hpp"

void RPN::plus(int a, int b)
{
	// cout << " + " << endl;
	stack.push(a + b);
	// cout << stack.top() << endl;
}

void RPN::minus(int a, int b)
{
	// cout << " - " << endl;
	stack.push(a - b);
	// cout << stack.top() << endl;
}

void RPN::multiply(int a, int b)
{
	// cout << " * " << endl;
	stack.push(a * b);
	// cout << stack.top() << endl;
}

void RPN::divide(int a, int b)
{
	// cout << " / " << endl;
	stack.push(a / b);
	// cout << stack.top() << endl;
}

bool is_number(const std::string &s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

bool check_valid(const char c)
{
	if ((c < 48 || c > 57))
	{
		if (c != 42 && c != 43 && c != 45 && c != 47)
			throw RPN::Error();
	}
	return (1);
}

RPN::RPN(string &exp)
{
	string yes, type;
	int i, a, b = 0;
	void (RPN::*funct[])(int a, int b) = {&RPN::plus, &RPN::minus, &RPN::multiply, &RPN::divide};
	string arr[] = {"+", "-", "*", "/"};
	for (int x = 0; x < (int)exp.size() + 1; x++)
	{
		if (exp[x] != ' ' && exp[x])
		{
			if (check_valid(exp[x]))
				yes.push_back(exp[x]);
			i = 0;
			while (i < 4 && arr[i].compare(yes))
				i++;
			if (i < 4)
			{
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				// cout << "calculating " << a << " " << b << " which " << i << endl;
				(this->*funct[i])(b, a);
			}
		}
		else
		{
			if (is_number(yes))
				stack.push(std::atoi(yes.c_str()));
			yes.clear();
		}
	}
	cout << stack.top() << endl;
}

RPN::RPN(const RPN &R)
{
	cout << "Copy constructor called" << endl;
	*this = R;
}

RPN &RPN::operator=(const RPN &R)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &R)
	{
		this->stack = R.stack;
	}
	return (*this);
}

RPN::~RPN()
{
}