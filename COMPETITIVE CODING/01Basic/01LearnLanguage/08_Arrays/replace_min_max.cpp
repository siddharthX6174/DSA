#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	int n{};
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// find min max pair algo
	int mn, mx, mnidx, mxidx, i = 0;

	if (n % 2 == 0) {
		//even
		if (a[0] < a[1]) {
			mn = a[0];
			mx = a[1];
			mnidx = 0;
			mxidx = 1;
		} else {
			mn = a[1];
			mx = a[0];
			mnidx = 1;
			mxidx = 0;
		}

		i = i + 2;
	} else {
		// odd
		mn = mx = a[0];
		mnidx = 0;
		mxidx = 0;
		i = i + 1;
	}

	while (i < n - 1) {
		int local_min , local_max;
		int local_minidx, local_maxidx;

		if (a[i] < a[i + 1]) {
			local_min = a[i];
			local_max = a[i + 1];
			local_minidx = i;
			local_maxidx = i + 1;
		} else {
			local_min = a[i + 1];
			local_max = a[i];
			local_minidx = i + 1;
			local_maxidx = i;
		}


		if (local_max > mx) {
			mx = local_max;
			mxidx = local_maxidx;
		}

		if (local_min < mn) {
			mn = local_min;
			mnidx = local_minidx;
		}

		i = i + 2;
	}

	swap(a[mnidx], a[mxidx]);

	for (auto x : a) {
		cout << x << " ";
	}

	return 0;
}