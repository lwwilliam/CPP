#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &A);
		WrongAnimal &operator = (const WrongAnimal &A);
		virtual void makeSound() const;
		std::string getType() const;
		~WrongAnimal();
	protected:
		std::string type;
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		void makeSound() const;
		~WrongCat();
};

#endif