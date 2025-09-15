#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int a[20000]; // height

// bottom up (recursion from back)
int F1(int n, int dp[]) {
	if (n == 1) {
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int Op1 = abs(a[n] - a[n - 1]) + F1(n - 1, dp);

	int Op2 = INT_MAX;
	if (n - 2 >= 1) {
		Op2 = abs(a[n] - a[n - 2]) + F1(n - 2, dp);
	}

	return dp[n] = min(Op1, Op2);
}

// bottom up (recursion from front)
int F2(int i, int n, int dp[]) {
	if (i == n) {
		return 0;
	}

	if (dp[i] != -1) {
		return dp[i];
	}

	int Op1 = abs(a[i] - a[i + 1]) + F2(i + 1, n, dp);

	int Op2 = INT_MAX;
	if (i + 2 <= n) {
		Op2 = abs(a[i] - a[i + 2]) + F2(i + 2, n, dp);
	}

	return dp[i] = min(Op1, Op2);
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {   // use 1-based indexing
		cin >> a[i];
	}

	int dp1[n + 1];
	int dp2[n + 2];

	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));

	cout << F1(n, dp1) << endl;
	cout << F2(1, n, dp2) << endl;

	return 0;
}
