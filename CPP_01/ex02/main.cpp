#include <iostream>

int main()
{
	std::string str =  "HI THIS IS BRAIN"; // variable
	std::string *stringPTR = &str; // pointer
	std::string &stringREF = str; // reference

	std::cout << "Variable: " << str << std::endl;
	std::cout << "Pointer: " << stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;
}