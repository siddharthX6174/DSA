#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>arr;
	int a;
	while (cin >> a) {
		arr.push_back(a);
	}
	// sort first
	sort(arr.begin(), arr.end());
	if (arr.size() % 2 != 0) {
		cout << arr[arr.size() / 2] << "\n";
	} else {
		// avg of two middle
		cout << (arr[arr.size() / 2] + arr[(arr.size() - 1) / 2]) / 2.0 << "\n";
	}
	return 0;
}