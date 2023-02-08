#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor is called" << std::endl;
}

Animal::Animal(const Animal &A)
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = A;
}

Animal &Animal::operator = (const Animal &A)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &A)
		type = A.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "makeSound is called"  << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

Animal::~Animal()
{
	std::cout << "Destructor is called" << std::endl;
}

Dog::Dog()
{
	std::cout << "Dog constructor is called" << std::endl;
	this->B = new Brain;
	Animal::type = "Dog";
}

void Dog::makeSound() const
{
	std::cout << "Woof!!!!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog detructor is called" << std::endl;
	delete B;
}

Cat::Cat()
{
	std::cout << "Cat constructor is called" << std::endl;
	this->B = new Brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow...." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat detructor is called" << std::endl;
	delete B;
}
