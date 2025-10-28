#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, int> mp;
	int a;

	while (cin >> a) {
		mp[a]++;
	}

	for (auto &x : mp) {
		cout << x.first << " ";
	}
	return 0;
}
