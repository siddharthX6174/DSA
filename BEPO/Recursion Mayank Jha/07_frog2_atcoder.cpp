#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, k;
int h[105];

int solve(int pos) {

	if (pos == n) return 0;   // reached last stone

	int ans = INT_MAX;

	for (int j = 1; j <= k; j++) {
		int cost = INT_MAX;
		if (pos + j <= n) {
			cost = abs(h[pos + j] - h[pos]) + solve(pos + j);
			ans = min(ans, cost);
		}
	}

	return ans;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	cout << solve(1);   // start from stone 1
	return 0;
}
