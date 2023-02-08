#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(const Animal &A);
		Animal &operator = (const Animal &A);
		virtual void makeSound() const;
		std::string getType() const;
		
		virtual ~Animal();
	protected:
		std::string type;
};

class Dog : public Animal
{
	public:
		Dog();
		void makeSound() const;
		~Dog();
	private:
		Brain *B;
};

class Cat : public Animal
{
	public:
		Cat();
		void makeSound() const;
		~Cat();
	private:
		Brain *B;
};

#endif