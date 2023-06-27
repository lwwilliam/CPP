#include "PmergeMe.hpp"

bool check_dup(std::vector<int> vec)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	bool result = false;
	for (it = vec.begin(); it != vec.end(); ++it)
	{
		for (it2 = it + 1; it2 != vec.end(); it2++)
		{
			if (*it == *it2)
			{
				result = true;
				throw PmergeMe::Duplicate();
				break;
			}
		}
	}
	return (result);
}

template <typename T>
std::vector<T> splitToVector(const std::string &s, char del)
{
	std::stringstream ss(s);
	std::string word;
	std::vector<T> vec;

	while (std::getline(ss, word, del))
	{
		std::istringstream iss(word);
		T value;
		if (iss >> value)
		{
			if (value < 0)
				throw PmergeMe::Negative();
			else
				vec.push_back(value);
		}
		else
			throw PmergeMe::Error();
	}
	return (vec);
}

PmergeMe::PmergeMe(string &arr)
{
	string num;
	num_arr = splitToVector<int>(arr, ' ');
	check_dup(num_arr);
	for (std::vector<int>::iterator i = num_arr.begin(); i != num_arr.end(); ++i)
		cout << *i << " ";
	cout << endl;
	cout << num_arr.size() << endl;
}

PmergeMe::~PmergeMe()
{
}