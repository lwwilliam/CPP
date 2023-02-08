#include "Animal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Default constructor is called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &A)
{
	std::cout << "Copy constructor is called" << std::endl;
	*this = A;
}

AAnimal &AAnimal::operator = (const AAnimal &A)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &A)
		type = A.type;
	return (*this);
}

void AAnimal::makeSound() const
{
	std::cout << "makeSound is called"  << std::endl;
}

std::string AAnimal::getType() const
{
	return (type);
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor is called" << std::endl;
}

Dog::Dog()
{
	std::cout << "Dog constructor is called" << std::endl;
	this->B = new Brain;
	AAnimal::type = "Dog";
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
