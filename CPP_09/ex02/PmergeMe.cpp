#include "PmergeMe.hpp"

template <typename T>
void check_dup(T vec)
{
	typename T::iterator it;
	typename T::iterator it2;
	for (it = vec.begin(); it != vec.end(); ++it)
	{
		for (it2 = it; it2 != vec.end(); it2++)
		{
			if (*it == *it2 && it != it2)
				throw PmergeMe::Duplicate();
		}
	}
}

double timestamp(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}

template <typename T>
T splitToSTL(const string &s, char del)
{
	std::stringstream ss(s);
	string word;
	T vec;

	while (std::getline(ss, word, del))
	{
		std::istringstream iss(word);
		int value;
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

template <typename V, typename T>
V insert(T arr)
{
	int f, s = 0;
	V pair_arr;
	for (typename T::iterator i = arr.begin(); i != arr.end(); ++i)
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


template <typename T>
void insertionSort(T& pairs, int n)
{
	if (n <= 1)
		return;

	typename T::iterator iter = pairs.begin();
	std::advance(iter, n - 1); // Move the iterator to the last element

	typename T::value_type last = *iter;

	typename T::iterator j = iter;
	--j;

	while (j != pairs.begin() && last.second < (*j).second) {
		*std::next(j) = *j;
		--j;
	}

	if (last.second < (*j).second)
		*std::next(j) = *j;

	*std::next(j) = last;

	insertionSort(pairs, n - 1);
}

// void insertionSort(std::vector<int>& arr, int n)
// {
// 	if (n <= 1)
// 		return;

// 	insertionSort(arr, n - 1);

// 	int last = arr[n - 1];
// 	int j = n - 2;

// 	while (j >= 0 && arr[j] > last)
// 	{
// 		arr[j + 1] = arr[j];
// 		j--;
// 	}

// 	arr[j + 1] = last;
// }

int Jacobsthal(int n)
{
	if (n <= 0)
		return (0);
	int J_num[n + 1];

	J_num[0] = 0;
	J_num[1] = 1;

	for (int i = 2; i <= n; i++)
		J_num[i] = J_num[i - 1] + 2 * J_num[i - 2];

	return (J_num[n]);
}

template <typename T>
void Jacob(T &S, T &pend)
{
	T tmp_pend;
	int pend_size = pend.size();
	// cout << endl << "pend: ";
	// for (typename T::iterator i = pend.begin(); i != pend.end(); ++i)
	// 	cout << *i << " ";
	// cout << endl << "S: ";
	// for (typename T::iterator i = S.begin(); i != S.end(); ++i)
	// 	cout << *i << " ";
	// cout << endl;
	for (int x = 2; x < pend_size; x++)
	{
		int J_num = Jacobsthal(x);
		if (J_num > pend_size)
			break;
		tmp_pend.push_back(pend.at(J_num - 1));
		typename T::iterator i = lower_bound(S.begin(), S.end(), pend.at(J_num - 1));
		S.insert(S.begin() + (i - S.begin()), pend.at(J_num - 1));
		pend.at(J_num - 1) = -1;
	}
	for (int x = 0; x < pend_size; x++)
	{
		if (pend.at(x) != -1)
		{
			typename T::iterator i = lower_bound(S.begin(), S.end(), pend.at(x));
			S.insert(S.begin() + (i - S.begin()), pend.at(x));
			tmp_pend.push_back(pend.at(x));
		}
	}
	pend.clear();
	pend = tmp_pend;
}

template <typename P, typename C>
void split_chain(P &p, C &S, C &pend)
{
	C tmp_pend;
	for(int i = 0; i < p.size(); i++)
	{
		pend.push_back(p[i].first);
		S.push_back(p[i].second);
	}
	S.insert(S.begin(), pend.front());
	if (!pend.empty())	
	{
		pend.erase(pend.begin());
	}
	Jacob<C>(S, pend);
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
	pairs = insert<vector< std::pair<int, int> >, vector<int> >(num_arr);
	insertionSort<vector< std::pair<int, int> > >(pairs, pairs.size());
	// for(int i = 0; i < pairs.size(); i++)
	// {
	// 	cout << "(" << pairs[i].first << "," << pairs[i].second << ")" << " ";
	// }
	// cout << endl;
	split_chain<vector< std::pair<int, int> >, vector<int> >(pairs, large_chain, small_chain);
	if (iseven == false)
	{
		vector<int>::iterator i = lower_bound(large_chain.begin(), large_chain.end(), last);
		if (i == large_chain.end())
			large_chain.push_back(last);
		else
			large_chain.insert(large_chain.begin() + (i - large_chain.begin()), last);
	}
	num_arr.clear();
	num_arr = large_chain;
}

void PmergeMe::algo_list()
{
	int last, f, s = 0;
	bool iseven = true;
	std::pair<int, int> P1;
	list< std::pair<int, int> > pairs;
	list<int> large_chain;
	list<int> small_chain;

	if (num_arr_list.size() % 2 == 1)
	{
		last = num_arr_list.back();
		iseven = false;
		num_arr_list.pop_back();
	}
	pairs = insert<list< std::pair<int, int> >, list<int> >(num_arr_list);
	insertionSort<list< std::pair<int, int> > >(pairs, pairs.size());
	// for(int i = 0; i < pairs.size(); i++)
	// {
	// 	cout << "(" << pairs[i].first << "," << pairs[i].second << ")" << " ";
	// }
	// cout << endl;
	// split_chain<list< std::pair<int, int> >, list<int> >(pairs, large_chain, small_chain);
	if (iseven == false)
	{
		list<int>::iterator i = lower_bound(large_chain.begin(), large_chain.end(), last);
		if (i == large_chain.end())
			large_chain.push_back(last);
		// else
			// large_chain.insert(large_chain.begin() + (i - large_chain.begin()), last);
	}
	num_arr_list.clear();
	num_arr_list = large_chain;
}

PmergeMe::PmergeMe(string &arr)
{
	double start, start_list, end, end_list;
	start = timestamp();
	num_arr = splitToSTL< vector<int> >(arr, ' ');
	check_dup< vector<int> >(num_arr);
	cout << "Before :  ";
	for (vector<int>::iterator i = num_arr.begin(); i != num_arr.end(); ++i)
		cout << *i << " ";
	cout << endl;
	algo();
	cout << "After :   ";
	for (vector<int>::iterator i = num_arr.begin(); i != num_arr.end(); ++i)
		cout << *i << " ";
	cout << endl;
	end = timestamp();

	start_list = timestamp();
	num_arr_list = splitToSTL< list<int> >(arr, ' ');
	check_dup< list<int> >(num_arr_list);
	cout << "Before :  ";
	for (list<int>::iterator i = num_arr_list.begin(); i != num_arr_list.end(); ++i)
		cout << *i << " ";
	cout << endl;
	algo_list();
	cout << "After :   ";
	for (list<int>::iterator i = num_arr_list.begin(); i != num_arr_list.end(); ++i)
		cout << *i << " ";
	cout << endl;
	end_list = timestamp();

	cout << "Time to process a range of " << num_arr.size() << " element with std::vector : "<< end - start << " us" << endl;
	// cout << "Time to process a range of " << num_arr_list.size() << " element with std::list : "<< end_list - start_list << " us" << endl;
	if (std::is_sorted(num_arr.begin(), num_arr.end()))
		cout << "Vector is sorted" << endl;
	else
		cout << "Vector is not sorted" << endl;
}

PmergeMe::~PmergeMe()
{
}
