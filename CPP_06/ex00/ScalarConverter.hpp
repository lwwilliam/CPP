#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class ScalarConverter
{
private:
	char	inchar;
	int 	inint;
	float	infloat;
	double	indouble;
public:
	ScalarConverter(string convert);
	~ScalarConverter();
	bool	onlydigit(string s);
	string	charcon(string c);
	string	intcon(string c);
	string	floatcon(string c);
	string	doublecon(string c);
};




#endif