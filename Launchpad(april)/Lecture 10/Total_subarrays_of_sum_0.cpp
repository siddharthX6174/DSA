#include<iostream>
#include<climits>
using  namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	//Create prefix array.

	int pre[n + 1] {0};
	pre[0] = a[0];

	int maxi = INT_MIN;
	int mini = INT_MAX;

	for (int i = 1; i < n; i += 1) {
		pre[i] = pre[i - 1] + a[i];
		if (pre[i] > maxi) {
			maxi = pre[i];
		}

		if (mini > pre[i]) {
			mini = pre[i];
		}
	}

	//THis is a frequency array based on prefix array.
	int freq[maxi - mini + 1] {0};


	freq[0] += 1;
	int ans = 0;//Total Subarrays jinka sum 0 hain.
	for (int i = 0; i < n; i += 1) {
		int ce = pre[i];
		freq[ce] += 1;
	}

	for (int i = 0; i < maxi - mini + 1; i += 1) {
		ans += (freq[i] * (freq[i] - 1)) / 2;
	}

	cout << ans << endl;


}