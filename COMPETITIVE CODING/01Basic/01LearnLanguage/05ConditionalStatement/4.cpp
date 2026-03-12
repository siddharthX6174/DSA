#include<iostream>
using namespace std;

int main() {
	char c;
	cin >> c;

	if (isdigit(c)) {
		cout << "IS DIGIT\n";
		return 0;
	} else {
		cout << "ALPHA\n";
		if (c <= 96 and c >= 65) {
			cout << "IS CAPITAL\n";
			return 0;
		} else {
			cout << "IS SMALL\n";
			return 0;
		}
	}

	return 0;
}