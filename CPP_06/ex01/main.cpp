#include "Serialization.hpp"

int main()
{
	Data data;

	data.inchar = 'c';
	data.inint = 42;
	data.infloat = 3.14f;
	data.indouble = 3.69;

	uintptr_t serializedData = Serializer::serialize(&data);
	Data *deserializedData = Serializer::deserialize(serializedData);

	if (&data == deserializedData)
	{
		std::cout << "Deserialization successful!" << std::endl;
	}
	else
	{
		std::cout << "Deserialization failed!" << std::endl;
	}
	return 0;
}