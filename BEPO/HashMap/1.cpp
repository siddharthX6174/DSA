/*
	store the frequency of elements in the array..
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr;
	int a{};
	while (cin >> a) {
		arr.push_back(a);
	}

	map<int, int> mp;
	for (int s : arr) {
		mp[s]++;
	}

	for (auto& x : mp) {
		cout << x.first << " --> " << x.second << endl;
	}
	return 0;
}