#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


vector<int> digits;
int maxi = INT_MIN;

void make_digit(int n) {
	while (n > 0) {
		digits.push_back(n % 10);
		n = n / 10;
	}
	reverse(digits.begin(), digits.end());
	return;
}

void get_num() {
	int n = 0;
	for (int& x : digits) {
		n = n * 10 + x;
	}
	maxi = max(maxi, n);
	return;
}

void max_num() {
	// original number
	get_num();
	for (int i = 0; i < digits.size(); i++) {
		if (digits[i] == 6) {
			digits[i] = 9;
			get_num();
			break;
		}
	}
	return;
}

int main() {
	fast();

	int n{};
	cin >> n;

	make_digit(n);

	for (auto& x : digits) {
		cout << x << " ";
	}
	cout << "\n";

	// get comapring numbers
	max_num();

	// print final number
	cout << maxi << "\n";

	return 0;
}