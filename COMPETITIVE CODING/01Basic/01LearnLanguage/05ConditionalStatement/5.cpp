#include<iostream>
using namespace std;

int main() {
	int a{}, b{};
	char s{};
	cin >> a >> s >> b;

	bool ans = false;

	if (s == '=') {
		if ( a == b ) ans = true;
	} else if (s == '>') {
		if (a > b) ans = true;
	} else {
		if (a < b) ans = true;
	}

	if (ans) {
		cout << "Right\n";
	} else {
		cout << "Wrong\n";
	}
}