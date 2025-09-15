# include <iostream>
# include <cstring>
using namespace std;

/*
	Dp[i] = F(i) : ith finbonacci number
*/


// Computation : No of unique states * Transition Time
// Computation : No of States * Transition Time
// Computation : n+1 * 1 ~= (n);

// Top down dp : Recursion + Memoisation
int F(int n, int*dp) {

	if (n == 1 or n == 0) {
		return n;
	}

	// check if the current state is unique or not ?
	// Currently we are at the F(n) state if this is a repeated state its answer would have been store here

	// calculate krne se phle check
	if (dp[n] != -1) {
		// This is a repeated state and you don't need to calculate the answer of this sstate and you can return the value;
		return dp[n];
	}

	int Op1 = F(n - 1, dp);
	int Op2 = F(n - 2, dp);


	// if you are here then you have calculated the answer for the unique state nowe store it.

	// and return se phle store.
	return dp[n] = Op1 + Op2;
}

// Iterative Dp :

int F2(int n) {

	int dp[n + 1] {};
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {

	int n;
	cin >> n;

	int dp[n + 1];
	memset(dp, -1, sizeof(dp)); // this can only be used to initialiise the containcer with values -1,0,1;


	cout << F(n, dp) << endl;

	cout << F2(n) << endl;
	return 0;
}