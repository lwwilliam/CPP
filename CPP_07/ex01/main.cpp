#include "Iter.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	char carr[] = {'a', 'b', 'c', 'd', 'e'};
	int n = sizeof(arr) / sizeof(arr[0]);

	iter<int>(arr, n, printElement);
	std::cout << std::endl;
	iter<char>(carr, n, printElement);
	std::cout << std::endl;
}