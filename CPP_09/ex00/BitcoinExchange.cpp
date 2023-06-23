#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange &B)
{
	cout << "Copy constructor called" << endl;
	*this = B;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &B)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &B)
	{
		this->data = B.data;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(string filename)
{
	BitcoinExchange::openFile();
	int x = 0;
	std::ifstream file(filename.c_str());
	if (!file)
	{
		throw BitcoinExchange::OpenFail();
	}
	string line;
	while (std::getline(file, line))
	{
		if (x++ == 0)
			continue;
		std::stringstream ss(line);
		std::string date;
		double value;
		if (std::getline(ss, date, '|') && ss >> value)
		{
			std::map<string, double>::reverse_iterator rit(data.lower_bound(date));
			if (rit == data.rend())
			{
				cout << "Key " << date << "not found in the map." << endl;
			}
			else if (value < 0)
				cout << "Error: not a positive number." << endl;
			else if (value > 1000)
				cout << "Error: too large a number." << endl;
			else
				cout << date << "=> " << value << " = " << rit->second * value << endl;
		}
		else
			cout << "Error: bad input => " << date << endl;
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::openFile()
{
	int x = 0;
	std::fstream file;
	file.open("./data.csv", std::ios::in);
	std::map<string, double> row;
	string temp, key, word;
	while (file >> temp)
	{
		if (x++ == 0)
			continue;
		bool iskey = 0;
		std::stringstream s(temp);
		while (getline(s, word, ','))
		{
			if (iskey == 0)
			{
				key = word;
				iskey = 1;
			}
			else
				row[key] = std::atof(word.c_str());
		}
	}
	this->data = row;
	// std::map<string, double>::iterator it;
	// for (it = row.begin(); it != row.end(); it++)
	// 	cout << it->first << "," << it->second << endl;
}

// std::vector<std::string> split(const std::string &s, char del)
// {
// 	std::stringstream ss(s);
// 	std::string word;
// 	std::vector<string> tokens;

// 	while (std::getline(ss, word, del))
// 	{
// 		tokens.push_back(word);
// 	}

// 	return (tokens);
// }

// string trimTrailingSpaces(string str)
// {
// 	string trimmed = str;

// 	// Find the last non-space character
// 	size_t lastCharIndex = trimmed.find_last_not_of(" ");

// 	// Erase the trailing spaces
// 	if (lastCharIndex != string::npos)
// 		trimmed.erase(lastCharIndex + 1);

// 	return (trimmed);
// }