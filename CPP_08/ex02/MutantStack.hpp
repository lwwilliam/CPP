#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef std::stack<T> stack;
	typedef typename stack::container_type::iterator iterator;
	MutantStack() {}
	~MutantStack() {}
	iterator begin()
	{
		return stack::c.begin();
	}
	iterator end()
	{
		return stack::c.end();
	}
};
