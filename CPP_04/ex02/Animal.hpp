#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &A);
		AAnimal &operator = (const AAnimal &A);
		virtual void makeSound() const;
		std::string getType() const;
		virtual ~AAnimal();
	protected:
		std::string type;
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