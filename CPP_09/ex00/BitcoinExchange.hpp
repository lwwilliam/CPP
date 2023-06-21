#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

class BitcoinExchange
{
private:
	std::map<string, double> data;

public:
	BitcoinExchange(string filename);
	~BitcoinExchange();
	void openFile();
	class OpenFail : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Unable to open file";
		}
	};
};
