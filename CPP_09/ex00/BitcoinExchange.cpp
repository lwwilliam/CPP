#include "BitcoinExchange.hpp"

std::vector<std::string> split(const std::string &s, char del)
{
	std::stringstream ss(s);
	std::string word;
	std::vector<string> tokens;

	while (std::getline(ss, word, del))
	{
		tokens.push_back(word);
	}

	return (tokens);
}

BitcoinExchange::BitcoinExchange(string filename)
{
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
			std::vector<std::string> a = split(date, '-');
			for (size_t i = 0; i < a.size(); i++)
				std::cout << a[i] << std::endl;
			// cout << date << endl;
			// cout << value << endl;
		}
		else
			cout << "fail" << endl;
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