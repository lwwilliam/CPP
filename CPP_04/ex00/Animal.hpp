#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &A);
		Animal &operator = (const Animal &A);
		virtual void makeSound() const;
		std::string getType() const;
		~Animal();
	protected:
		std::string type;
};

class Dog : public Animal
{
	public:
		Dog();
		void makeSound() const;
		~Dog();
};

class Cat : public Animal
{
	public:
		Cat();
		void makeSound() const;
		~Cat();
};

#endif