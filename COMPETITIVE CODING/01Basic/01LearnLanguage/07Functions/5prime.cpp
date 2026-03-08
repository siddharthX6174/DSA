#include<iostream>
using namespace std;

bool isPrime(int x) {

	if (x < 2) return false;

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}

	return true;
}

int main() {

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (isPrime(i))
			cout << i << " ";
	}

	return 0;
}