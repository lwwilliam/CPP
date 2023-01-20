#include<iostream>

using namespace std;

int	main(int ac, char **av)
{
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int x = 1; av[x]; x++)
	{
		for (int y = 0; av[x][y]; y++)
			cout << (char)(toupper(av[x][y]));
	}
	cout << "\n";
	return(0);
}