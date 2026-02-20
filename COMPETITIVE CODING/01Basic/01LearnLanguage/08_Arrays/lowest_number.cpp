#include<iostream>
using namespace std;
#include<vector>

int main() {
	int n;
	cin >> n;

	int k = INT_MAX;
	int idx = -1;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		if (a < k) {
			k = a;
			idx = i;
		}
	}

	cout << k << " " << idx << endl;
	return 0;
}