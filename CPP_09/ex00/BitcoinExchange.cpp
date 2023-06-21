#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::openFile()
{
	int x = 0;
	std::fstream file;
	file.open("./test.csv", std::ios::in);
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
				row[key] = std::stod(word);
		}
	}
	this->data = row;
	std::map<string, double>::iterator it;
	for (it = row.begin(); it != row.end(); it++)
		cout << it->first << "," << it->second << endl;
}