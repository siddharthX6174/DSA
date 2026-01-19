#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];

		// n == 2 is always YES
		if (n == 2) {
			cout << "YES\n";
			continue;
		}

		vector<int> freq(n + 2, 0);
		for (int x : a) {
			if (x <= n)
				freq[x]++;
		}

		// Compute MEX
		int M = 0;
		while (freq[M] > 0)
			M++;

		// Count elements < M
		int cnt = 0;
		for (int i = 0; i < M; i++)
			cnt += freq[i];

		if (cnt == M)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}