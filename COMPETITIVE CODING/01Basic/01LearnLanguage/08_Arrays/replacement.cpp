#include<iostream>
using namespace std;

int main() {
	int n{};
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a > 0) {
			cout << 1 << " ";
		} else if (a < 0) {
			cout << 2 << " ";
		} else {
			cout << 0 << " ";
		}
	}

	return 0;
}