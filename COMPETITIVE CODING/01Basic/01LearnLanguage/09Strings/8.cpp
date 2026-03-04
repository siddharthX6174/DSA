#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s); // read the entire line including commas

	for (char c : s) {
		if (c == ',') {
			cout << ' '; // replace comma with space
		} else if (c >= 'a' && c <= 'z') {
			cout << char(c - 32); // lowercase to uppercase
		} else if (c >= 'A' && c <= 'Z') {
			cout << char(c + 32); // uppercase to lowercase
		}
	}
	cout << endl;
	return 0;
}