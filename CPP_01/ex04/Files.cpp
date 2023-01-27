#include "Files.hpp"

Files::Files(char *f, char *s1, char *s2)
{
	std::string str1(s1);
	std::string str2(s2);
	filename = f;
	string1 = str1;
	string2 = str2;
	// std::cout << filename << " " + string1 << " " + string2 << std::endl;
}

void	Files::openfile(void)
{
	std::string file_str;
	std::ifstream myfile (filename);
	outfile = strcat(filename, ".replace");
	std::ofstream output(outfile);
	if (myfile.is_open())
	{
		while(getline (myfile, file_str))
		{
			Files::replace(file_str, string1, string2);
		}
		myfile.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
	return;
}

void Files::replace(std::string s, std::string s1, std::string s2)
{
	std::string ans = "";
	for (int i = 0; (unsigned)i < s.length(); i++)
	{
		int k = 0;
		if (s[i] == s1[k] && i + s1.length() <= s.length())
		{
			int j;
			for (j = i; (unsigned)j < i + s1.length(); j++)
			{
				if (s[j] != s1[k])
					break;
				else 
					k = k + 1;
			}
			if ((unsigned)j == i + s1.length())
			{
				ans.append(s2);
				i = j - 1;
			}
			else
				ans.push_back(s[i]);
		}
		else
			ans.push_back(s[i]);
	}
	std::ofstream of;
	of.open(outfile, std::ios::app);
	of << ans << "\n";
	of.close();
}

Files::~Files()
{
	return;
}