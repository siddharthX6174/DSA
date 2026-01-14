#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

int32_t main() {
	int a = 20, b = 12;

	cout << gcd(a, b) << endl;
	return 0;
}