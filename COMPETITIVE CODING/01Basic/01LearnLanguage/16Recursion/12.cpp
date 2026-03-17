#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long ans = 1e18;

void solve(int i, long long& curr, long long total, vector<int>& a) {
	if (i == a.size()) {
		ans = min(ans, abs(total - 2 * curr));
		return;
	}

	// choose curr oen
	curr += a[i];
	solve(i + 1, curr, total, a);
	curr -= a[i];

	// unchoose
	solve(i + 1, curr, total, a);
}

int main() {
	fast();

	int n;
	cin >> n;
	vector<int> a(n);
	long long total = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	long long curr = 0;
	solve (0, curr, total, a);

	cout << ans << "\n";

	return 0;
}