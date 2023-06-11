#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(string convert)
{
	cout << "char: " << ScalarConverter::charcon(convert) << endl;
	cout << "int: " << ScalarConverter::intcon(convert) << endl;
	cout << "float: " << ScalarConverter::floatcon(convert) << endl;
	cout << "double: " << ScalarConverter::doublecon(convert) << endl;
}

bool	ScalarConverter::onlydigit(string s)
{
	for (int x = 0; x < (int)s.size(); x++)
		if(isdigit(s[x]))
			return(1);
	return (0);
}

string	ScalarConverter::charcon(string c)
{
	long num;
	stringstream ss(c);

	ss >> num;
	if (!onlydigit(c))
		return("impossible to convert");
	else if (num > 127 || num < 32)
		return("impossible to print");
	else if (!isprint(num))
		return("Non displayable");
	else
	{
		this->inchar = (char)num;
		std::ostringstream oss;
		oss << "'" << static_cast<char>(num) << "'";
		return(oss.str());
	}
}

string	ScalarConverter::intcon(string c)
{
	long num;
	stringstream ss(c);

	ss >> num;
	if (!onlydigit(c))
		return("impossible");
	else if (num > 2147483647 || num < -2147483648)
		return("impossible");
	else
	{
		std::ostringstream oss;
		oss << num;
		this->inint = num;
		return(oss.str());
	}
}

string	ScalarConverter::floatcon(string c)
{
	float f = std::atof(c.c_str());
	this->infloat = f;
	std::ostringstream oss;
	if (std::floor(f) == f)
		oss << f << ".0" << "f";
	else
		oss << f << "f";
	return (oss.str());
}

string	ScalarConverter::doublecon(string c)
{
	float f = std::atof(c.c_str());
	this->indouble = f;
	std::ostringstream oss;
	if (std::floor(f) == f)
		oss << f << ".0";
	else
		oss << f;
	return (oss.str());
}

ScalarConverter::~ScalarConverter()
{
	// cout << "Scalar Destructing" << endl;
}

