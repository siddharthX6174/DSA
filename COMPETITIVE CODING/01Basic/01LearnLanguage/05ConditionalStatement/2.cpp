#include<iostream>
using namespace std;

int main() {
	int a{}, b{};
	cin >> a >> b;

	bool ismultiple = false;
	if (a % b == 0 or b % a == 0) ismultiple = true;

	if (ismultiple) {
		cout << "Multiples\n";
	} else {
		cout << "No Multiples\n";
	}

	return 0;
}