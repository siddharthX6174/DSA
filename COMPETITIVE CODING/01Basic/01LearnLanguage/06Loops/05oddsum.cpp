#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;

		if (x > y) {
			swap(x, y);
		}

		int sum = 0;
		for (int i = x + 1; i < y; i++) {
			if (i % 2 == 1) sum += i;
		}
		cout << sum << "\n";
	}
	return 0;
}