#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

using std::cout;
using std::endl;
using std::string;

class PmergeMe
{
private:
	std::vector<int> num_arr;

public:
	PmergeMe(string &arr);
	~PmergeMe();
	class Error : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error!";
		}
	};
	class Duplicate : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error Duplicated number is found!";
		}
	};
	class Negative : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error Negative number is found!";
		}
	};
};
