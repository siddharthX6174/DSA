// dp

#include<bits/stdc++.h>
using namespace std;

vector<int>dp;

int solve(int i, int n, vector<int>& nums, int k) {
	if (i == n) {
		return nums[i];
	}

	if (dp[i] != INT_MIN) {
		return dp[i];
	}

	int ans = INT_MIN;

	for (int jump = 1; jump <= k and i + jump <= n ; jump++) {
		ans = max(ans,  nums[i] + solve(i + jump, n, nums, k));
	}

	return dp[i] = ans;;
}



int maxResult(vector<int>& nums, int k) {
	int n = nums.size() - 1;
	dp.assign(nums.size(), INT_MIN);
	return solve(0, n, nums, k);
}



int main() {
	int k;
	cin >> k;

	vector<int> nums;
	int x;
	while (cin >> x) {
		nums.push_back(x);
	}

	cout << maxResult(nums, k);
	return 0;
}