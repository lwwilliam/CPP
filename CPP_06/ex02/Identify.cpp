#include "Identify.hpp"

Base * generate(void)
{
	int random = rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{

	if (dynamic_cast<A*> (p) != nullptr)
	{
		cout << "A" << endl;
	}
	else if (dynamic_cast<B*> (p) != nullptr)
	{
		cout << "B" << endl;
	}
	else if (dynamic_cast<B*> (p) != nullptr)
	{
		cout << "C" << endl;
	}
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} 
	catch (std::bad_cast&) 
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast&) 
		{
			try 
			{
				dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} 
			catch (std::bad_cast&) 
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}