// first half in ascending
// second half in descending
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int>arr;
	int x;
	while (cin >> x) {
		arr.push_back(x);
	}

	int n = arr.size();
	sort(arr.begin(), arr.end());
	reverse(arr.begin() + n / 2, arr.end());

	for (int& x : arr) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}