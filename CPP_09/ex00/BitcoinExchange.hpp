#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class BitcoinExchange
{
private:
	std::map<string, double> data;

public:
	BitcoinExchange(/* args */);
	~BitcoinExchange();
	void openFile();
};
