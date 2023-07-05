#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <sys/time.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;

class PmergeMe
{
private:
	vector<int> num_arr;
	list<int> num_arr_list;

public:
	PmergeMe(string &arr);
	~PmergeMe();
	void algo();
	void algo_list();
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
	class Sorted : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Array is already sorted!";
		}
	};
};
