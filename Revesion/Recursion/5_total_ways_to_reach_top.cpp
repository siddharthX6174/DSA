#include <iostream>
#include <vector>
#include <cstring>
int n {}; // nth stair

// recursion from front
int count_stair_path(int curr_stair) {
	if (curr_stair == n) return 1;

	int op1 = 0, op2 = 0;

	// step of 1 is always valid
	op1 = count_stair_path(curr_stair + 1);

	// step of 2 only if it doesn’t overshoot
	if (curr_stair + 2 <= n) {
		op2 = count_stair_path(curr_stair + 2);
	}

	return op1 + op2;
}

// recursion from back
int count_back(int i) {
	if (i == 0) return 1;

	int op1 = 0, op2 = 0;

	// step of -1 always valid if i >= 1
	if (i - 1 >= 0) {
		op1 = count_back(i - 1);
	}

	// step of -2 only if valid
	if (i - 2 >= 0) {
		op2 = count_back(i - 2);
	}

	return op1 + op2;
}

// DP memoization
std::vector<int> dp1;

int count_stair_path_2(int curr_stair) {
	if (curr_stair == n) return 1;

	if (dp1[curr_stair] != -1) return dp1[curr_stair];

	int op1 = 0, op2 = 0;

	// step of 1
	op1 = count_stair_path_2(curr_stair + 1);

	// step of 2 only if valid
	if (curr_stair + 2 <= n) {
		op2 = count_stair_path_2(curr_stair + 2);
	}

	return dp1[curr_stair] = op1 + op2;
}


// dp from back
std::vector<int> dp2;
int count_back_2(int i) {
	if (i == 0) return 1;

	if (dp2[i] != -1) {
		// check
		return dp2[i];
	}

	int op1 = 0, op2 = 0;

	// step of -1 always valid if i >= 1
	if (i - 1 >= 0) {
		op1 = count_back_2(i - 1);
	}

	// step of -2 only if valid
	if (i - 2 >= 0) {
		op2 = count_back_2(i - 2);
	}

	return dp2[i] = op1 + op2;
}


// iterative dp building up with recursion from back

std::vector<int> dp;

int solve(int i) {
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {
	std::cin >> n;

	// plain recursion
	std::cout << count_stair_path(0) << std::endl;

	// back recursion
	std::cout << count_back(n) << std::endl;

	// dp memoization
	dp1.assign(n + 1, -1);
	count_stair_path_2(0);          // fills dp1[0]
	std::cout << dp1[0] << std::endl;  // now safe to print

	dp2.assign(n + 1, -1);
	count_back_2(n);
	std::cout << dp2[n] << std::endl;

	dp.assign(n + 1, -1);
	std::cout << solve(n) << std::endl;;
}
