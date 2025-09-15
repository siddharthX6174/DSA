#include <iostream>
#include <vector>
#include <cmath>    // for abs
#include <algorithm> // for min
using namespace std;

int n; // number of stones
vector<int> h; // heights of stones


// recursion from front
int fun(int i) {
	// base: if we're on the last stone, no cost
	if (i == n) {
		return 0;
	}

	// option 1: jump to next stone
	int op1 = 1e9; // large number
	if (i + 1 <= n) {
		op1 = abs(h[i] - h[i + 1]) + fun(i + 1);
	}

	// option 2: jump over one stone
	int op2 = 1e9;
	if (i + 2 <= n) {
		op2 = abs(h[i] - h[i + 2]) + fun(i + 2);
	}

	return min(op1, op2);
}

// recursion from back
int back(int n) {
	// base
	if (n == 1) {
		return 0;
	}

	// option 1 : reached from 4th stone
	int op1 = 1e9;
	if (n - 1 >= 1) {
		op1 = abs(h[n] - h[n - 1]) + back(n - 1);
	}
	// opion 2 : reached from 3rd stone
	int op2 = 1e9;
	if (n - 2 >= 1) {
		op2 = abs(h[n] - h[n - 2]) + back(n - 2);
	}

	return min(op1, op2);
}



// dp memoization from front
vector<int> dp1;

int fun2(int i) {
	// base: if we're on the last stone, no cost
	if (i == n) {
		return 0;
	}

	if (dp1[i] != -1) {
		return dp1[i];
	}

	// option 1: jump to next stone
	int op1 = 1e9; // large number
	if (i + 1 <= n) {
		op1 = abs(h[i] - h[i + 1]) + fun2(i + 1);
	}

	// option 2: jump over one stone
	int op2 = 1e9;
	if (i + 2 <= n) {
		op2 = abs(h[i] - h[i + 2]) + fun2(i + 2);
	}

	return dp1[i] = min(op1, op2);
}


// dp memoirzation in recursion from back
vector<int> dp2;

int back2(int n) {
	// base
	if (n == 1) {
		return 0;
	}

	if (dp2[n] != -1) {
		return dp2[n];
	}
	// option 1 : reached from 4th stone
	int op1 = 1e9;
	if (n - 1 >= 1) {
		op1 = abs(h[n] - h[n - 1]) + back2(n - 1);
	}
	// opion 2 : reached from 3rd stone
	int op2 = 1e9;
	if (n - 2 >= 1) {
		op2 = abs(h[n] - h[n - 2]) + back2(n - 2);
	}

	return dp2[n] = min(op1, op2);
}


// iterative dp
vector<int> dp;
int iterative_dp () {
	dp[1] = 0;
	dp[2] = abs(h[2] - h[1]);

	for (int i = 3; i <= n; i++) {
		int op1 = 1e9;
		if (i - 1 >= 1) {
			op1 = dp[i - 1] + abs(h[i] - h[i - 1]);
		}

		int op2 = 1e9;
		if (i - 2 >= 1) {
			op2 = dp[i - 2] + abs(h[i] - h[i - 2]);
		}

		dp[i] = min(op1, op2);
	}

	return dp[n];
}

int main() {
	cin >> n;
	h.resize(n + 1); // 1-based indexing

	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	cout << fun(1) << endl; // start from first stone (index 1)

	cout << back(n) << endl;

	dp1.assign(n + 1, -1);
	fun2(1);
	cout << dp1[1] << endl;

	dp2.assign(n + 1, -1);
	back2(n);
	cout << dp2[n] << endl;

	dp.assign(n + 1, 1e9);
	cout << iterative_dp() << endl;


	return 0;
}
