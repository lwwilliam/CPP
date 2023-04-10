#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	public:
		virtual void makeSound() const;
		std::string getType() const;
		virtual ~AAnimal();
		AAnimal &operator = (const AAnimal &A);
	protected:
		AAnimal();
		std::string type;
		AAnimal(const AAnimal &A);
};

class Dog : public AAnimal
{
	public:
		Dog();
		void makeSound() const;
		~Dog();
	private:
		Brain *B;
};

class Cat : public AAnimal
{
	public:
		Cat();
		void makeSound() const;
		~Cat();
	private:
		Brain *B;
};

#endif