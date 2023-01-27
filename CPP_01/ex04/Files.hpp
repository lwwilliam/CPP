#ifndef FILES_H
#define FILES_H

#include <iostream>
#include <fstream>
#include <cstring>

class Files
{
	private:
		char *filename;
		char *outfile;
		std::string string1;
		std::string string2;
	public:
		Files(char *f, char *s1, char *s2);
		void	openfile(void);
		void	replace(std::string s, std::string s1, std::string s2);
		~Files();
};

#endif