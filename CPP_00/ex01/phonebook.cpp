#include "phonebook.hpp"

int	Phonebook::Add(void)
{
	std::string f, l, n, p, s;
	int	empty_check = 0; // if 0 is empty if 1 is empty
	std::cout << "<Adding Contact>" << std::endl;
	std::cout << "Enter Firstname:" << std::endl;
	getline(std::cin, f);
	if (f.empty())
		empty_check = 1;
	std::cout << "Enter Lastname:" << std::endl;
	getline(std::cin, l);
	if (l.empty())
		empty_check = 1;
	std::cout << "Enter Nickname:" << std::endl;
	getline(std::cin, n);
	if (n.empty())
		empty_check = 1;
	std::cout << "Enter Phone Number:" << std::endl;
	getline(std::cin, p);
	if (p.empty())
		empty_check = 1;
	std::cout << "Enter Darkest Secret:" << std::endl;
	getline(std::cin, s);
	if (s.empty())
		empty_check = 1;
	if (empty_check == 0)
	{
		Contact contact(f, l, n, p, s);
		which_contact %= 8;
		contacts[which_contact] = contact;
		which_contact++;
		std::cout << "Contact is added " << which_contact << std::endl;
	}
	else
		std::cout << "All field must be filled!" << std::endl;
	return(0);
}

std::string	print_check(std::string &s)
{
	int x = s.length();
	if (x >= 10)
	{
		s.resize(10);
		s[9] = '.';
	}
	return(s);
}

void	print(Contact contact, int x)
{
	std::cout << std::right << std::setfill(' ') 
		<< std::setw(10) << x << ".|"
		<< std::setw(10) << print_check(contact.Firstname) << "|"
		<< std::setw(10) << print_check(contact.Lastname) << "|"
		<< std::setw(10) << print_check(contact.Nickname) << "|"
		<< std::endl;

}

int	Phonebook::Search(Phonebook book)
{
	std::stringstream s;
	int			x;
	std::string id;
	getline(std::cin, id);
	s << id;
	s >> x;
	if (x < 1 || x > 8)
		std::cout << "invalid index" << std::endl;
	else
		print(book.contacts[x - 1], x);
	return(0);
}

Phonebook::Phonebook(void)
{
	std::cout << "------<Command list>---------\n" << "1. ADD    (to add contact)\n"
		<< "2. SEARCH (to search contact)\n" << "3. EXIT   (exit program)" << std::endl;
	which_contact = 0;
}


int main(void)
{
	Phonebook book;
	Contact tact;
	std::string command;
	while (command.compare("EXIT"))
	{
		getline(std::cin, command);
		if (command.compare("ADD") == 0)
			book.Add();
		else if (command.compare("SEARCH") == 0)
			book.Search(book);
	}
	return(0);
}