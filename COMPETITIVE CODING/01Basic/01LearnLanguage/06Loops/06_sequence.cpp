#include<iostream>
using namespace std;

int main() {
	int x , y;
	while (cin >> x >> y) {
		if (x <= 0 or y <= 0) {
			return 0;
		}

		if (x > y) {
			swap(x, y);
		}

		int sum = 0;
		for (int i = x; i <= y; i++) {
			cout << i << " ";
			sum += i;
		}

		cout << "sum =" << sum << "\n";
	}
	return 0;
}