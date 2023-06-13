#include "Iter.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	// char carr[] = {'a', 'b', 'c', 'd', 'e'};

	::iter<int>(arr, 5, printElement<int>);
}