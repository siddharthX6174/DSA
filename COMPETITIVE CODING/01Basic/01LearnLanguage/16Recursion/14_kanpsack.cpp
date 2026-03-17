#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long maxi = LLONG_MIN;

void solve (int i, long long curr, long long value, long long w, vector<pair<int, int>>& a) {
	if (i == a.size()) {
		maxi = max(maxi, value);
		return;
	}

	// taking curr..
	if (curr + a[i].first <= w) {
		solve(i + 1, curr + a[i].first, value + a[i].second, w, a);
	}

	// not taking
	solve(i + 1, curr, value, w, a);
}

int main() {
	fast();

	int n;
	cin >> n;
	long long w;
	cin >> w;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int wi, vi;
		cin >> wi >> vi;
		a[i] = {wi, vi};
	}

	long long curr = 0;
	long long value = 0;
	solve(0, curr, value, w, a);

	cout << maxi << "\n";

	return 0;
}