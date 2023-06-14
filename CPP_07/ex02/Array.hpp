#pragma once
#include <iostream>

using	std::cout;
using	std::endl;

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
	private:
		T *arr;
};
