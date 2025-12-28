#include<bits/stdc++.h>
using namespace std;

bool check(int n) {
	string s = to_string(n);
	map<char, int>mp;
	for (auto c : s) {
		mp[c]++;
	}
	// merepas frequency storre hochuki hai sabki ab count check karo
	int i = mp[s[0]];
	for (auto x : mp) {
		if (x.second != i) {
			return false;
		}
	}
	return true;
}

int main() {
	int n{};
	cin >> n;

	vector<int> arr;

	int a;
	while (cin >> a) {
		arr.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		if (check(arr[i])) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}

/*
n = 7
n-2) -> arr = {1 2 4 6 7
}

3 5

cost 0(n) O (1)
*/


/*
	array input of size of n
	elemnts of aray 1->1e4
	stable:
		each digit has same frequewncy in a given number
			123
			1-1
			2-1
			3-1

			print stable number

			n = 3

			12 122 1122

*/