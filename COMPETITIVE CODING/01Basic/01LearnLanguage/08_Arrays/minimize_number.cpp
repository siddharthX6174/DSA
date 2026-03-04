#include<iostream>
#include<vector>
using namespace std;

bool iseven(vector<int>& a) {
	bool isvn = true;
	for (auto x : a) {
		if (x % 2 != 0) {
			isvn = false;
		}
	}

	if (isvn) {
		for (int i = 0; i < a.size(); i++) {
			a[i] = a[i] / 2;
		}
	}

	return isvn;
}

int main() {
	int n{};
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int oprn = 0;
	while (iseven(a)) {
		oprn = oprn + 1;
	}

	cout << oprn << endl;

	return 0;
}