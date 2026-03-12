#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main() {
	vector<int>a(3);
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}

	vector<int>b = a;
	sort(b.begin(), b.end());
	for (auto& x : b) {
		cout << x << "\n";
	}
	cout << "\n";

	for (auto& x : a) {
		cout << x << "\n";
	}
	return 0;
}