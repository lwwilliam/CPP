#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int len, T (*funct)(T&))
{
	for (int x = 0; x < len; x++)
		funct(array[x]);
}

template <typename T>
void printElement(T& element)
{
    std::cout << element << " ";
}


#endif