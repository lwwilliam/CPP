#include "phonebook.hpp"

Contact::Contact(void)
{
	return;
}

Contact::Contact(std::string f, std::string l, std::string n, std::string p, std::string s)
{
	this->Firstname = f;
	this->Lastname = l;
	this->Nickname = n;
	this->Phonenumber = p;
	this->DarkestSecret = s;
}

std::string Contact::GetFName()
{
	return(this->Firstname);
}

std::string Contact::GetLName()
{
	return(this->Lastname);
}

std::string Contact::GetNName()
{
	return(this->Nickname);
}

std::string Contact::GetPHN()
{
	return(this->Phonenumber);
}

std::string Contact::GetDS()
{
	return(this->DarkestSecret);
}