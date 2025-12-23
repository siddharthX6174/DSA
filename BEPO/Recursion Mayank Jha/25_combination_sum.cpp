#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

int a[] {2, 3, 6, 7};
int target = 7;


void solve(int idx, int sum, vector<int>&current) {

	if (sum == target) {
		ans.push_back(current);
		return;
	} else if (sum > target) {
		return;
	}


	for (int i = idx; i < 4; i++) {
		// taking current element again and again
		current.push_back(a[i]);
		sum += a[i];
		solve(i , sum, current);

		// backtrack
		sum -= a[i];
		current.pop_back();
	}
}


int main() {
	int sum = 0;
	vector<int>current;
	solve(0, sum, current);

	for (auto& row : ans) {
		for (auto& x : row) {
			cout << x << " ";
		}
		cout << '\n';
	}

	return 0;
}

/// combination sum 2
// sort and check also ek eleemtn multiple times nahi aaskta hai !!