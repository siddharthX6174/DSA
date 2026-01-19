#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdint>
using namespace std;
#define int long long

const int N = 1e5 + 7;

int dp[N];

int solve(int i, int* h, int n) {

	if (i == n) {
		return 0;
	}

	// phle check
	if (dp[i] != -1) {
		return dp[i];
	}

	// i+1
	int op1 = LLONG_MAX;
	if (i + 1 <= n) {
		op1 = abs(h[i] - h[i + 1]) + solve(i + 1, h, n);
	}


	// i+2
	int op2 = LLONG_MAX;
	if (i + 2 <= n) {
		op2 = abs(h[i + 2] - h[i]) + solve(i + 2, h, n);
	}

	return dp[i] = min(op1, op2);
}

int32_t main() {
	int n{};
	cin >> n;
	int h[n] {};
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	fill(dp, dp + n, -1);

	solve(0, h, n - 1);

	cout << dp[0] << endl;

	return 0;
}