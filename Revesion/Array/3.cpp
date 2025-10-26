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

	// map automatically sorts the elemtnt
	for (auto &x : mp) {
		if (x.second > n / 2) {
			cout << x.first << " ---> " << x.second << "\n";
		}
	}

	return 0;
}
