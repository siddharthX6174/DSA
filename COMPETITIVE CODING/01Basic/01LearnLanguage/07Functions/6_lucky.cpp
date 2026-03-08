#include<iostream>
#include<map>
using namespace std;

bool f(int i) {
	string s = to_string(i);
	map<char, int> mp;

	for (char &c : s) {
		mp[c]++;
	}

	for (auto &x : mp) {
		if (x.first != '4' && x.first != '7') {
			return false;
		}
	}

	return true;
}

int main() {
	int a{}, b{};
	cin >> a >> b;

	bool found = false;

	for (int i = a; i <= b; i++) {
		if (f(i)) {
			cout << i << " ";
			found = true;
		}
	}

	if (!found) cout << -1;

	return 0;
}