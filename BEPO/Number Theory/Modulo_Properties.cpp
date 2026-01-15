#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
#define int long long
int Fact[N] {0};

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
/*z
	Inverse of y with respect to p:

	(y^-1) % P:

	According to FLT: (y^P-2) % P
*/
// O(log y)
int Inverse(int y) {
	return FastPowerV2(y, P - 2);
}


// Based on Fermat's little theorem...
int Division(int x, int y) {
	return (Multiply(x, Inverse(y)));
}

// O(n) : Large Factorial->....
void calculate_Factorial() {
	Fact[0] = 1;
	for (int i = 1; i < N; i++) {
		Fact[i] = Multiply(Fact[i - 1], i);
	}
}

//O(log n)
int ncr(int n, int r) {
	// ncr = n! / (r!*(n-r)!)

	return Multiply( Multiply(Fact[n], Inverse(Fact[r])), Inverse(Fact[n - r]));
}

// n p r
int npr(int n, int r) {
	/*
		npr = n! / (n-r)!;
	*/
	return Multiply(Fact[n], Inverse(Fact[n - r]));
}
int32_t main() {

	cout << FastPowerV2(3, 8) << endl;
	calculate_Factorial();

	cout << npr(1000, 500) << endl;
	return 0;
}