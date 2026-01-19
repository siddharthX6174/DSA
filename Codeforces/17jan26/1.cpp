#include<bits/stdc++.h>
using namespace std;

int main() {
	int t{};
	cin >> t;

	while (t--) {
		int n{};
		cin >> n;
		vector<pair<int, bool>>a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (i % 2 == 0) {
				a.push_back({x, true});
			} else {
				a.push_back({x, false});
			}
		}

		sort(a.begin(), a.end());
		bool ans = true;

		for (int i = 1; i < n; i++) {
			if (a[i].second == a[i - 1].second) {
				ans = false;
			}
		}

		if (ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}