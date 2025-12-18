#include<iostream>
using namespace std;

int n;
char output[15];

void solve(int i, char max_character) {

	if (i == n) {
		output[i] = '\0';
		cout << output << endl;
		return;
	}

	for (char ch = 'a'; ch <= max_character; ch++) {
		output[i] = ch;

		if (ch == max_character) {
			solve(i + 1, max_character + 1);
		} else {
			solve(i + 1, max_character);
		}
	}
}

int main() {
	cin >> n;
	solve(0, 'a');
	return 0;
}