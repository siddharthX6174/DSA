#include <iostream>
using namespace std;
char input[200];

void permute(int start) {

	if (input[start] == '\0') {
		cout << input << endl;
		return;
	}

	for (int end = start; input[end] != '\0'; end++) {
		swap(input[start], input[end]);
		permute(start + 1);
		// fix the problem by retaining the original state
		swap(input[start], input[end]); // backtracking
	}
}

int main() {
	cin >> input;

	permute(0);
}

// yeh ahi character array par galat answer derh hai but agar iski jgh string se karoge toh shi dega..
// arrays are by default passed by reference while string is not passed by the refernce...
// for (int end = start; end < s.length(); end++)
