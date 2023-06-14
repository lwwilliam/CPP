#include "Array.tpp"

int main() {
	// Test default constructor
	Array<int> arr1;
	cout << "arr1 size: " << arr1.size() << endl; // Output: 0

	// Test constructor with size parameter
	Array<int> arr2(5);
	cout << "arr2 size: " << arr2.size() << endl; // Output: 5

	// Test subscript operator
	arr2[0] = 10;
	arr2[1] = 20;
	arr2[2] = 30;
	cout << "arr2[0]: " << arr2[0] << endl; // Output: 10
	cout << "arr2[1]: " << arr2[1] << endl; // Output: 20
	cout << "arr2[2]: " << arr2[2] << endl; // Output: 30

	// Test out of bounds exception
	try {
		cout << "arr2[5]: " << arr2[5] << endl; // Throws std::out_of_range exception
	} catch (const std::exception& e) {
		cout << "Exception: " << e.what() << endl; // Output: Array index out of range
	}
	return 0;
}