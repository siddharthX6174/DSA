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

		for (int start = 0; start < n; start++) {
			for (int end = start; end < n; end++) {

				int maxi = INT_MIN;
				for (int k = start; k <= end; k++) {
					maxi = max(maxi, a[k]);
				}
				cout << maxi << " ";
			}
		}
		cout << endl;
	}

	return 0;
}