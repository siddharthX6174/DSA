// generalised from of staircase problem

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n{}, k{};
vector<int>h; // height of stones


// recursion from front
int front(int i) {

	if (i == n) {
		return 0;
	}

	int ans = 1e9; // This variable will store my min cost accross all paths

	for (int jump = 1; jump <= k; jump++) {
		int op = 1e9;
		if (jump + i <= n) {
			op = abs(h[i] - h[i + jump]) + front(i + jump);
		}
		ans = min(op, ans);
	}

	return ans;
}



// recursionn from back
int back(int n) {

	if (n == 1) {
		return 0;
	}

	int ans = 1e9;

	for (int jump = 1; jump <= k; jump ++) {
		int op = 1e9;
		if (n - jump >= 1) {
			op = abs(h[n] - h[n - jump]) + back(n - jump);
		}
		ans = min(op, ans);
	}

	return ans;
}


// Dp memoization from front
vector<int> dp1;
int front_dp(int i) {

	if (i == n) {
		return 0;
	}

	if (dp1[i] != 1e9) {
		return dp1[i];
	}

	int ans = 1e9; // This variable will store my min cost accross all paths

	for (int jump = 1; jump <= k; jump++) {
		int op = 1e9;
		if (jump + i <= n) {
			op = abs(h[i] - h[i + jump]) + front_dp(i + jump);
		}
		ans = min(op, ans);
	}

	return dp1[i] = ans;
}


// Dp memoization from back
vector<int> dp2;
int back_dp(int n) {

	if (n == 1) {
		return 0;
	}

	if (dp2[n] != 1e9) {
		return dp2[n];
	}

	int ans = 1e9;

	for (int jump = 1; jump <= k; jump ++) {
		int op = 1e9;
		if (n - jump >= 1) {
			op = abs(h[n] - h[n - jump]) + back_dp(n - jump);
		}
		ans = min(op, ans);
	}

	return dp2[n] = ans;
}


// iterative dp build on the basis of recursionn from back and building up from front in dp
vector<int> dp;
int iterative_dp() {
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		int ans = 1e9;

		for (int jump = 1; jump <= k; jump++) {
			int op = 1e9;

			if (i - jump >= 1) {
				op = abs(h[i] - h[i - jump]) + dp[i - jump];
			}

			ans = min(op, ans);
		}

		dp[i] = ans;
	}

	return dp[n];
}


int main() {
	cin >> n >> k;
	h.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	cout << front(1) << endl;
	cout << back(n) << endl;

	dp1.assign(n + 1, 1e9);
	front_dp(1);
	cout << dp1[1] << endl;

	dp2.assign(n + 1, 1e9);
	back_dp(n);
	cout << dp2[n] << endl;

	dp.assign(n + 1, 1e9);
	cout << iterative_dp() << endl;

}