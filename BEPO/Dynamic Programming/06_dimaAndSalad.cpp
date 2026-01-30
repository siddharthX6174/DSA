#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
#define int long long

int n, k;
vector<int> tast, calorie;
int dp[100][2 * N];

int solve(int i, int sum) {
	if (i == n) {
		if (sum == 0) {
			return 0;
		} else {
			return -1e12;
		}
	}
	if (dp[i][sum + N] != -1) {
		return dp[i][sum + N];
	}
	int op1 = taste[i] + solve(i + 1, sum + (taste[i] - (k * calorie[i])));
	int op2 = 0 + solve(i + 1, sum);
	return dp[i][sum + N] = max(op1, op2);
}

int32_t main() {
	cin >> n >> k;
	taste.resize(n);
	calorie.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = Solve(0, 0);

	if (ans <= 0) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}
}