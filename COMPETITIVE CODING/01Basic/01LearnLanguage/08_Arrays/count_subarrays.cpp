#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t{};
	cin >> t;
	while (t--) {
		int n{};
		cin >> n;
		int a[n] {};
		for (int i = 0; i < n; i++) cin >> a[i];

		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {

				bool increasing = true;
				int prev = a[i];
				for (int k = i + 1; k <= j; k++) {
					if (a[k] < prev) increasing = false;
					prev = a[k];
				}
				if (increasing) ans++;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}