#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;


int a[200001] {};
int n;
int dp[200001] {};


// Dp[i] = F(i) = min(dp[i-1], dp[i-2])
// Dp[i] : min cost from 1st to ith stone.
// Definiition is like recursion from front but we are implementing it like recursion from back.
// co-realtion between : Recursion and Iteration (Reversse ka)

// Computation : n+1 * 1 ~= 200001

int F() {

	dp[1] = 0;
	dp[2] = abs(a[2] - a[1]);

	for (int i = 3; i <= n; i++) {
		int Op1 = abs(a[i] - a[i - 1]) + dp[i - 1];
		int Op2 = abs(a[i] - a[i - 2]) + dp[i - 2];

		dp[i] = min(Op1, Op2);
	}

	return dp[n];
}