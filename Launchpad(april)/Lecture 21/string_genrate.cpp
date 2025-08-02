#include<iostream>
using namespace std;

char input[100];
char output[100];


void F(int i, int j) {

	if (input[i] == '\0') {
		// i have found a ouput
		// sice it is a character array just put a null
		// character in the ouput array at the current
		// index and print it out
		output[j] = '\0';
		cout << output << endl;
		return ;
	}

	// Option 1 : When I don't take the current character.
	// You don't need to add anaything in output array,
	F(i + 1, j);



	// Option 2 : When i take the current character/
	// You need to add the current character in the output array.
	output[j] = input[i];
	F(i + 1, j + 1);

	return;
}



int main() {
	cin >> input;
	F(0, 0);
}