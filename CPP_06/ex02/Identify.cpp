#include "Identify.hpp"

Base * generate(void)
{
	int random = std::rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{

	if (dynamic_cast<A*> (p) != NULL)
	{
		cout << "A" << endl;
	}
	else if (dynamic_cast<B*> (p) != NULL)
	{
		cout << "B" << endl;
	}
	else if (dynamic_cast<C*> (p) != NULL)
	{
		cout << "C" << endl;
	}
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p) != NULL)
	{
		std::cout << "A" << std::endl;
	} 
	else if (dynamic_cast<B*>(&p) != NULL)
	{
		std::cout << "B" << std::endl;
	} 
	else if (dynamic_cast<C*>(&p) != NULL) 
	{
		std::cout << "C" << std::endl;
	}
}

int main() 
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Base* instance = generate();
	identify(instance);
	delete instance;

	return 0;
}
