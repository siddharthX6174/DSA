#include<bits/stdc++.h>
using namespace std;

int findMax(int i, int j, vector<int> &arr) {
	int maxi = 0;
	for (int x = i; x <= j; x++) {
		maxi = max(maxi, arr[x]);
	}
	return maxi;
}


int maxAmount(int i, int k, vector<int>&arr) {
	if (k <= 0 || i >= arr.size()) {
		return 0;
	}

	int maxSize = 0;

	for (int j = i + 1; j <= arr.size(); j++) {
		int maxi = findMax(i, j - i, arr);
		maxSize = max(maxSize, maxi + maxAmount(j, k - 1, arr));
	}
	return maxSize;
}


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int res = maxAmount(0, k, arr);
	cout << res << endl;
	return 0;

}