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

void insertionSort(list<std::pair<int, int> >& pairs, int n)
{
	list<std::pair<int, int> >::iterator current = pairs.begin();
	list<std::pair<int, int> >::iterator sortedEnd = pairs.begin();

	for (int i = 0; i < n; ++i)
	{
		std::pair<int, int> value = *current;
		list<std::pair<int, int> >::iterator insertPos = pairs.begin();

		while (insertPos != current && insertPos->second < value.second)
			++insertPos;

		if (insertPos != current)
		{
			pairs.erase(current);
			pairs.insert(insertPos, value);
			current = sortedEnd;
		}
		sortedEnd = current;
		++current;
	}
}

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

void Jacob(vector<int> &S, vector<int> &pend)
{
	vector<int> tmp_pend;
	int pend_size = pend.size();
	for (int x = 2; x < pend_size; x++)
	{
		int J_num = Jacobsthal(x);
		if (J_num > pend_size)
			break;
		tmp_pend.push_back(pend.at(J_num - 1));
		vector<int>::iterator i = lower_bound(S.begin(), S.end(), pend.at(J_num - 1));
		S.insert(S.begin() + (i - S.begin()), pend.at(J_num - 1));
		pend.at(J_num - 1) = -1;
	}
	for (int x = 0; x < pend_size; x++)
	{
		if (pend.at(x) != -1)
		{
			vector<int>::iterator i = lower_bound(S.begin(), S.end(), pend.at(x));
			S.insert(S.begin() + (i - S.begin()), pend.at(x));
			tmp_pend.push_back(pend.at(x));
		}
	}
	pend.clear();
	pend = tmp_pend;
}

void Jacob(list<int> &S, list<int> &pend)
{
	list<int> tmp_pend;
	int pend_size = pend.size();
	for (int x = 2; x < pend_size; x++)
	{
		int J_num = Jacobsthal(x);
		if (J_num > pend_size)
			break;
		list<int>::iterator i = pend.begin();
		std::advance(i, J_num - 1);
		tmp_pend.push_back(*i);
		list<int>::iterator low;
		for(low = S.begin(); low != S.end(); ++low)
			if (*low > *i)
				break;
		tmp_pend.insert(low, *i);
		*i = -1;
	}
	for (list<int>::iterator i = pend.begin(); i != pend.end(); ++i)
	{
		if (*i != -1)
		{
			tmp_pend.push_back(*i);
			list<int>::iterator low;
			for(low = S.begin(); low != S.end(); ++low)
				if (*low > *i)
					break;
			tmp_pend.insert(low, *i);
		}
	}
	pend.clear();
	pend = tmp_pend;
}

template <typename P, typename L>
void split_chain(P &p, L &S, L &pend)
{
	for(typename P::iterator i = p.begin(); i != p.end(); ++i)
	{
		pend.push_back(i->first);
		S.push_back(i->second);
	}
	S.insert(S.begin(), pend.front());
	if (!pend.empty())	
	{
		pend.erase(pend.begin());
	}
	// cout << endl;
	// cout << "pend: ";
	// for (typename L::iterator i = pend.begin(); i != pend.end(); ++i)
	// 	cout << "(" << *i << ")" << " ";
	// cout << endl;
	// cout << "S: ";
	// for (typename L::iterator i = S.begin(); i != S.end(); ++i)
	// 	cout << "(" << *i << ")" << " ";
	// cout << endl << endl;
	Jacob(S, pend);
}

void PmergeMe::algo()
{
	int last = 0;
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
	insertionSort(pairs, pairs.size());
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
	int last = 0;
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
	insertionSort(pairs, pairs.size());
	// for (list< std::pair<int, int> >::iterator i = pairs.begin(); i != pairs.end(); ++i)
	// 	cout << "(" << i->first << "," << i->second << ")" << " ";
	// cout << endl;
	split_chain<list< std::pair<int, int> >, list<int> >(pairs, large_chain, small_chain);
	if (iseven == false)
	{
		list<int>::iterator i = lower_bound(large_chain.begin(), large_chain.end(), last);
		if (i == large_chain.end())
			large_chain.push_back(last);
		else
		{
			list<int>::iterator low;
			for(low = large_chain.begin(); low != large_chain.end(); ++low)
				if (*low > last)
					break;
			large_chain.insert(low, last);
		}
	}
	num_arr_list.clear();
	num_arr_list = large_chain;
}

// bool check_sort( )

PmergeMe::PmergeMe(string &arr)
{
	double start, start_list, end, end_list;
	start = timestamp();
	num_arr = splitToSTL< vector<int> >(arr, ' ');
	check_dup< vector<int> >(num_arr);
	cout << "Vector Before :  ";
	for (vector<int>::iterator i = num_arr.begin(); i != num_arr.end(); ++i)
		cout << *i << " ";
	cout << endl;
	algo();
	cout << "Vector After :   ";
	for (vector<int>::iterator i = num_arr.begin(); i != num_arr.end(); ++i)
		cout << *i << " ";
	cout << endl;
	end = timestamp();

	start_list = timestamp();
	num_arr_list = splitToSTL< list<int> >(arr, ' ');
	check_dup< list<int> >(num_arr_list);
	cout << "List Before   :  ";
	for (list<int>::iterator i = num_arr_list.begin(); i != num_arr_list.end(); ++i)
		cout << *i << " ";
	cout << endl;
	algo_list();
	cout << "List After   :   ";
	for (list<int>::iterator i = num_arr_list.begin(); i != num_arr_list.end(); ++i)
		cout << *i << " ";
	cout << endl;
	end_list = timestamp();

	cout << "Time to process a range of " << num_arr.size() << " element with std::vector : "<< end - start << " us" << endl;
	cout << "Time to process a range of " << num_arr_list.size() << " element with std::list : "<< end_list - start_list << " us" << endl;
}

PmergeMe::~PmergeMe()
{
}

// if (std::is_sorted(num_arr.begin(), num_arr.end()))
// 	cout << "Vector is sorted" << endl;
// else
// 	cout << "Vector is not sorted" << endl;
// if (std::is_sorted(num_arr_list.begin(), num_arr_list.end()))
// 	cout << "List is sorted" << endl;
// else
// 	cout << "List is not sorted" << endl;
