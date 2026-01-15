#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int P = 1e9 + 10;
#define int long long

// Time Complexity: O(1)
// Addition Property of modulo:
int addition(int x, int y) {
	return (x + y) % P;
}

// Time Complexity: O(1)
// Subtraction Property of modulo:
int Subtraction(int x, int y) {
	return ((x - y) % P + 1 * P) % P;
}

// Time Complexity: O(1)
// Multiplication Property of modulo:
int Multiply(int x, int y) {
	return ((x % P) * (y % P) % P);
}

// Iterative way
// Time complexity: O(log y)
int FastPower(int x, int y) {
	int result = 1;

	while (y > 0) {
		if (y % 2 == 1) {
			result = x * result;
		}
		y = y / 2;
		x = x * x;
	}
	return result;
}

// faastest snippet
int FastPowerV2(int x, int y) {
	int result = 1;

	while (y > 0) {
		if (y % 2 == 1) {
			result = Multiply(x,  result); // use modulo multiply
		}
		y = y / 2;
		x = Multiply(x, x);
	}

	return result;
}


// (x/y)%P
/*

*/

int32_t main() {
	cout << FastPowerV2(3, 8) << endl;
}