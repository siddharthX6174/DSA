#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // number of steps
vector<int> cost;

// recursion from front
int front(int i) {
	if (i >= n) return 0; // reached or passed top
	int op1 = cost[i] + front(i + 1);
	int op2 = cost[i] + front(i + 2);
	return min(op1, op2);
}

// recursion from back
int back(int i) {
	if (i < 0) return 0;
	if (i == 0) return cost[0];
	if (i == 1) return cost[1];
	int op1 = cost[i] + back(i - 1);
	int op2 = cost[i] + back(i - 2);
	return min(op1, op2);
}

// dp for front
vector<int> dp1;
int front_dp (int i) {
	if (i >= n) return 0; // reached or passed top
	if (dp1[i] != 1e9) {
		return dp1[i];
	}
	int op1 = cost[i] + front_dp(i + 1);
	int op2 = cost[i] + front_dp(i + 2);
	return dp1[i] = min(op1, op2);
}

// dp for back
vector<int> dp2;
int back_dp(int i) {
	if (i < 0) return 0;
	if (i == 0) return cost[0];
	if (i == 1) return cost[1];

	if (dp2[i] != 1e9) {
		return dp2[i];
	}
	int op1 = cost[i] + back_dp(i - 1);
	int op2 = cost[i] + back_dp(i - 2);
	return dp2[i] = min(op1, op2);
}

// iterative dp
int front_iterative() {
	vector<int> dp(n + 1, 0);
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < n; i++) {
		dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
	}
	return min(dp[n - 1], dp[n - 2]); // answer is min of last two
}


int main() {
	cin >> n;
	cost.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	cout << "Front recursion: " << min(front(0), front(1)) << endl;
	cout << "Back recursion: "  << min(back(n - 1), back(n - 2)) << endl;

	dp1.assign(n + 1, 1e9);
	cout << "Front recursion + DP: " << min(front_dp(0), front_dp(1)) << endl;

	dp2.assign(n + 1 , 1e9);
	cout << "back recursion + dp: " << min(back_dp(n - 1), back_dp(n - 2)) << endl;
}
