#include<iostream>
using namespace std;

long long fact[21] {};

int main() {
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= 20; i++) {
		fact[i] = i * fact[i - 1];
	}

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		cout << fact[x] << "\n";
	}

	return 0;
}