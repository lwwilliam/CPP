#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

static void	_displayTimestamp(void)
{
	std::time_t now = time(0);
	std::tm *t = localtime(&now);
	std::cout << "[" << 1900 + t->tm_year
		<< std::setw(2) << std::setfill('0') << t->tm_mon
		<< std::setw(2) << std::setfill('0') << t->tm_mday
		<< "_" << std::setw(2) << std::setfill('0') << t->tm_hour
		<< std::setw(2) << std::setfill('0') << t->tm_min
		<< std::setw(2) << std::setfill('0') << t->tm_sec
		<< "]" << std::endl;
}
