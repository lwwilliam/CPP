#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &W)
{
	std::cout << "WrongAnimal Copy constructor is called" << std::endl;
	*this = W;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &W)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &W)
		type = W.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makeSound is called"  << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor is called" << std::endl;
}

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor is called" << std::endl;
	WrongAnimal::type = "WrongAnimal";
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Cat sound" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called" << std::endl;
}