#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int len, void (*funct)(T&))
{
	for (int x = 0; x < len; x++)
		funct(array[x]);
}

template <typename P>
void printElement(P arr)
{
    std::cout << arr << " ";
}

#endif