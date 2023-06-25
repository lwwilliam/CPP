#include "PmergeMe.hpp"

bool check_valid(const char c)
{
	if ((c < 48 || c > 57))
	{
		throw PmergeMe::Error();
	}
	return (1);
}

PmergeMe::PmergeMe(string &arr)
{
	string num;
	for (int x = 0; x < (int)arr.size() + 1; x++)
	{
		if (arr[x] != ' ' && arr[x])
		{
			if (check_valid(arr[x]))
				num.push_back(arr[x]);
		}
		else
		{
			cout << num << endl;
			num.clear();
		}
	}
}

PmergeMe::~PmergeMe()
{
}