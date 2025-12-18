#include<iostream>
using namespace std;

char table[][10] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char output[15];
char input[15];

void solve(int i, int j) {

	// base condn
	if (input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}
	int current_digit = input[i] - '0';

	//F(0)=table[current_digit][k]+F(1);
	//k will go from 0 to table[current_digit] ka last index.

	// task
	for (int k = 0; table[current_digit][k] != '\0'; k++) {
		output[j] = table[current_digit][k];
		solve(i + 1, j + 1);
	}
}

int main() {
	cin >> input;
	solve(0, 0); // first index of input, first index of output array

}