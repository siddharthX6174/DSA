#include<iostream>
using namespace std;

char output[100];
int n;


void F(int index, char max_character) {


	if (index == n) {
		output[n] = '\0';
		cout << output << endl;
		return;
	}


	for (char ch = 'a' ; ch <= max_character; ch++) {
		output[index] = ch;

		if (ch == max_character) {
			F(index + 1, max_character + 1);
		} else {
			F(index + 1, max_character);
		}
	}
}

int main() {
	cin >> n;

	F(0, 'a');

}