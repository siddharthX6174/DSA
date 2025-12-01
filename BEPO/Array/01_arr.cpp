#include<iostream>
using namespace std;

int main() {
	int a[5] {22, 33, 44, 55, 66};

	/*
		here a -> address of the first block of the array
		cout << a - > prints address
		(a+1) -> address of second block

		*(a+1) -> value at first block
		[] -> value of (operator overloading)
	*/

	cout << "Printing the address and corresponding values\n";

	for (int i = 0; i < 5; i++) {
		cout << a + i << " --> " << *(a + i) << endl;
	}

	return 0;
}