#include "phonebook.hpp"

Contact::Contact()
{
	x = 0;
}

Contact::Contact(std::string f, std::string l, std::string n, std::string p, std::string s)
{
	this->Firstname = f;
	this->Lastname = l;
	this->Nickname = n;
	this->Phonenumber = p;
	this->DarkestSecret = s;
}
