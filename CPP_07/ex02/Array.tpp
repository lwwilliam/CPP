#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() {}

template <typename T>
Array<T>::Array(unsigned int n)
{
	T arr[n];
	this->arr = arr;
}