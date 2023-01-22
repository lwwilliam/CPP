#ifndef PHONEBOOK_H
#define  PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
	public:
		int x;
		std::string	Firstname;
		std::string	Lastname;
		std::string	Nickname;
		std::string	Phonenumber;
		std::string	DarkestSecret;
		Contact(std::string f, std::string l, std::string n, std::string p, std::string s);
		Contact();
};

class Phonebook
{
	public:
		Phonebook();
		int	Add(void);
		int	Search(Phonebook book);
		int which_contact;
		Contact contacts[8];

};

 

#endif