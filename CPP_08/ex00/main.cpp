#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(8);
	v.push_back(13);
	v.push_back(17);
	v.push_back(18);

	try
	{
		std::vector<int>::iterator result = easyfind(v, 4);
		std::cout << "Value found: " << *result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}