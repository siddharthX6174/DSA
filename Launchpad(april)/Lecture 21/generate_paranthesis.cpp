#include<iostream>
using namespace std;

int input;
char output[100];


void F( int j) {

	if (j == 2 * input) {
		// you hav efound a pattern and output , print it our.

		output[j] = '\0';
		cout << output << endl;
		return ;
	}

	// option 1 : Put the '(' and ask recursion to do the rest.

	output[j] = '(';
	F(j + 1);




	// option 2 : Put the ')' and ask recusion to do the rest.
	output[j] = ')';
	F(j + 1);
}

int main() {
	cin >> input;

	F(0);
}