#include<iostream>
using namespace std;

int main() {
	int a{}, b{};
	cin >> a >> b;

	bool e{false};

	if (a % b == 0) {
		e = true;
	}

	if (b % a == 0) {
		e = true;
	}

	if (e) {
		cout << "Multiples\n";
	} else {
		cout << "No Multiples\n";
	}

	return 0;
}