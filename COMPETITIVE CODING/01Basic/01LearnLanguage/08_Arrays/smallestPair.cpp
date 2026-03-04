#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {

	int t{};
	cin >> t;
	while (t--) {
		int n{};
		cin >> n;

		vector<int> a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int res = INT_MAX;
		for (int i = 0; i < n - 1; i++) {

			for (int j = i + 1; j < n; j++) {
				int sum = a[i] + a[j] + j - i;
				res = min(sum, res);
			}
		}

		cout << res << endl;
	}

	return 0;
}