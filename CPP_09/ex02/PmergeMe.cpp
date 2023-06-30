#include "PmergeMe.hpp"

void check_dup(vector<int> vec)
{
	vector<int>::iterator it;
	vector<int>::iterator it2;
	for (it = vec.begin(); it != vec.end(); ++it)
		for (it2 = it + 1; it2 != vec.end(); it2++)
			if (*it == *it2)
				throw PmergeMe::Duplicate();
}

long long timestamp(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

template <typename T>
vector<T> splitToVector(const string &s, char del)
{
	std::stringstream ss(s);
	string word;
	vector<T> vec;

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

vector< std::pair<int, int> > insert(vector<int> arr)
{
	int f, s = 0;
	vector< std::pair<int, int> > pair_arr;
	for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
	{
		std::pair<int, int> pair1;
		f = *i;
		i++;
		s = *i;
		if (f < s)
		{
			pair1.first = f;
			pair1.second = s;
		}
		else
		{
			pair1.first = s;
			pair1.second = f;
		}
		pair_arr.push_back(pair1);
	}
	return (pair_arr);
}

void insertionSort(vector< std::pair<int, int> > &pairs, int n)
{
	if (n <= 1)
		return;

	insertionSort(pairs, n - 1);

	std::pair<int, int> last = pairs[n - 1];
	int j = n - 2;

	while (j >= 0 && pairs[j].second > last.second)
	{
		pairs[j + 1] = pairs[j];
		j--;
	}
	pairs[j + 1] = last;
}

void insertionSort(std::vector<int>& arr, int n)
{
	if (n <= 1)
		return;

	insertionSort(arr, n - 1);

	int last = arr[n - 1];
	int j = n - 2;

	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}

	arr[j + 1] = last;
}

void split_chain(vector< std::pair<int, int> > &p, vector<int> &S, vector<int> &pend)
{
	for(int i = 0; i < p.size(); i++)
	{
		pend.push_back(p[i].first);
		S.push_back(p[i].second);
	}
	// cout << pend.front() << endl;
	S.push_back(pend.front());
	std::rotate(S.rbegin(), S.rbegin() + 1, S.rend());
	std::reverse(pend.begin(), pend.end());
	pend.pop_back();
	std::reverse(pend.begin(), pend.end());
}

void PmergeMe::algo()
{
	int last, f, s = 0;
	bool iseven = true;
	std::pair<int, int> P1;
	vector< std::pair<int, int> > pairs;
	vector<int> large_chain;
	vector<int> small_chain;

	if (num_arr.size() % 2 == 1)
	{
		last = num_arr.back();
		iseven = false;
		num_arr.pop_back();
	}
	pairs = insert(num_arr);
	cout << pairs.size() << endl;
	insertionSort(pairs, pairs.size());
	split_chain(pairs, large_chain, small_chain);
	for(int i = 0; i < pairs.size(); i++)
	{
		cout << "(" << pairs[i].first << "," << pairs[i].second << ")" << " ";
	}
	cout << endl << "p: ";
	for (vector<int>::iterator i = small_chain.begin(); i != small_chain.end(); ++i)
		cout << *i << " ";
	cout << endl << "S: ";
	for (vector<int>::iterator i = large_chain.begin(); i != large_chain.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

PmergeMe::PmergeMe(string &arr)
{
	long long start, end;
	start = timestamp();
	string num;
	num_arr = splitToVector<int>(arr, ' ');
	check_dup(num_arr);
	for (vector<int>::iterator i = num_arr.begin(); i != num_arr.end(); ++i)
		cout << *i << " ";
	cout << endl;
	algo();
	// cout << num_arr.size() << endl;
	// sort(num_arr.begin(), num_arr.end());
	cout << endl
		 << endl;
	for (vector<int>::iterator i = num_arr.begin(); i != num_arr.end(); ++i)
		cout << *i << " ";
	cout << endl;
	end = timestamp();
	cout << "time taken " << end - start << " usecond." << endl;
}

PmergeMe::~PmergeMe()
{
}
