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
		++which_contact;
		if (which_contact >= 3)
			which_contact %= 3;
		// if (which_contact <= 0 || which_contact < 8)
		// 	which_contact++;
		// else if (which_contact == 8)
		// 	which_contact = 1;
		contacts[which_contact] = contact;
		// contacts[(which_contact)++ % 8] = contact;
		std::cout << "Contact is added " << which_contact <<std::endl;
	}
	else
		std::cout << "All field must be filled!" << std::endl;
	return(0);
}

int	Phonebook::Search(void)
{
	std::string input;
	getline(std::cin, input);
	std::cout << "SEARCH " << input << std::endl;
	return(0);
}

Phonebook::Phonebook(void)
{
	std::cout << "------<Command list>---------\n" << "1. ADD    (to add contact)\n"
		<< "2. SEARCH (to search contact)\n" << "3. EXIT   (exit program)" << std::endl;
	which_contact = 0;
}

Contact::Contact()
{
	x = 0;
}

void	print(Contact contact)
{
		std::cout << contact.Firstname << std::endl;
		std::cout << contact.Lastname << std::endl;
		std::cout << contact.Nickname << std::endl;
		std::cout << contact.Phonenumber << std::endl;
		std::cout << contact.DarkestSecret << std::endl;
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
			book.Search();
	}
	for (int x = 0; x < 3; x++)
		print(book.contacts[x]);
	return(0);
}