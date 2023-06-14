#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : len(0)
{
	this->arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
	this->arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array &A) : len(A.len)
{
	cout << "Copy constructor called" << endl;
	*this = A;
}

template <typename T>
Array<T> &Array<T>::operator = (const Array &A)
{
	cout << "Copy assignment operator called" << endl;
	if(this != &A)
	{
		this->arr = new T[A.len];
		for (int x = 0; x < (int)A.len; x++)
			this->arr[x] = A.arr[x];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	cout << "Destructor called" << endl;
	delete[] arr;
}

template <typename T>
T& Array<T>::operator[](int num)
{
	if (num >= (int)this->len) 
	{
		throw Array::OutOfBound();
	}
	return (arr[num]);
}


template <typename T>
int	Array<T>::size()
{
	return (this->len);
}