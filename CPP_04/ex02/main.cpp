#include "Animal.hpp"
#include  "WrongAnimal.hpp"

// int main()
// {
// 	const AAnimal* meta = new AAnimal();
// 	const AAnimal* j = new Dog();
// 	const AAnimal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	// std::cout << k->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// return 0;
// }

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	//if give error then is correct 
	// AAnimal* e = new AAnimal();

	delete j;
	delete i;

	return 0;
}  
