#include <bits/stdc++.h>
using namespace std;

int main() {
	// map<pair<int, char>, int> mp;

	int n;
	cin >> n;

	// for (int i = 0; i < n; i++) {
	// 	int x;
	// 	char ch;

	// 	cin >> ch >> x;
	// 	mp.insert({{i, ch}, x});
	// }

	// for (auto &x : mp) {
	// 	cout << x.first.first << "-" << x.first.second
	// 	     << " --> " << x.second << endl;
	// }

	multimap<char, int> mp2;
	for (int i = 0; i < n; i++) {
		int x;
		char ch;

		cin >> ch >> x;
		mp2.insert({ch, x});
	}

	for (auto x : mp2) {
		cout << x.first << " " << x.second << "\n";
	}
	return 0;


	return 0;
}
