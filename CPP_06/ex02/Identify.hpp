#ifndef INDENTIFY_HPP
#define INDENTIFY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::cout;
using std::string;

class Base
{
	public:
		virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif