#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;


class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual std::string const & getType() const; //Returns the materia type
		virtual	~AMateria();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string	type;
};

#endif