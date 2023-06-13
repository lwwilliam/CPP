#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename S>
void swap(S &first, S &second) 
{
	S tmp;

	tmp = first;
	first = second;
	second = tmp;
}

template <typename I>
I min(I first, I second)
{
	if (first == second)
		return (second);
	else if (first < second)
		return (first);
	else
		return (second);
}

template <typename A>
A max(A first, A second)
{
	if (first == second)
		return (second);
	else if (first > second)
		return (first);
	else
		return (second);
}

#endif