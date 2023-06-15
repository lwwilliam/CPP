#include "Array.tpp"

int main() 
{
	Array<int> arr1;
	cout << "arr1 size: " << arr1.size() << endl;

	Array<int> arr2(5);
	cout << "arr2 size: " << arr2.size() << endl;

	arr2[0] = 69;
	arr2[1] = 70;
	arr2[2] = 71;
	cout << "arr2[0]: " << arr2[0] << endl;
	cout << "arr2[1]: " << arr2[1] << endl;
	cout << "arr2[2]: " << arr2[2] << endl;

	try
	{
		cout << "arr2[5]: " << arr2[5] << endl;
	} 
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	Array<int> cpy = arr2;
	cout << "arr2 size: " << cpy.size() << endl;

	cout << "cpy[0]: " << cpy[0] << endl;
	cout << "cpy[1]: " << cpy[1] << endl;
	cout << "cpy[2]: " << cpy[2] << endl;

	try
	{
		cout << "cpy[5]: " << cpy[5] << endl;
	} 
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	return 0;
}