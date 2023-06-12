#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

struct Data
{
	int		inint;
	char	inchar;
	float	infloat;
	double	indouble;
};

class Serializer
{
	public:
	// 	Serializer(string convert);	//constructor
	// 	Serializer(const Serializer &S);	// copy constructor
	// 	Serializer &operator=(const Serializer &S);	//copy assigment operator overload
	// 	~Serializer();	//destructor
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif