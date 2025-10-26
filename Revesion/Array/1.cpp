#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> freq(n + 1, 0);
	for (auto x : a) {
		freq[x]++;
	}

	map<int, int> mp; // element -> frequency
	for (int i = 0; i <= n; i++) {
		if (freq[i] > 0) {
			mp[i] = freq[i];
		}
	}

	// Switch key and value: frequency -> list of elements
	map<int, vector<int>> switched;
	for (auto &x : mp) {
		switched[x.second].push_back(x.first);
	}

	// Output the switched map
	for (auto &x : switched) {
		cout << x.first << " ---> ";
		for (auto val : x.second) {
			cout << val << " ";
		}
		cout << "\n"; 0
	}

	return 0;
}