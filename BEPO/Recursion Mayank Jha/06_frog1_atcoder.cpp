#include<iostream>
using namespace std;
#include<algorithm>
#include<climits>

int n {};
int h[100] {};

int solve(int i) {

	if (i == n) {
		return 0;
	}

	int op1 = abs(h[i + 1] - h[i]) + solve(i + 1);

	int op2 = INT_MAX;
	if (i + 2 <= n) {
		op2 = abs(h[i + 2] - h[i]) + solve(i + 2);
	}

	return min(op1, op2);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	cout << solve(1);
	return 0;
}