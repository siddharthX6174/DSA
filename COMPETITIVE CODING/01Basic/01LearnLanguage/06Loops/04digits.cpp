#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		if (n == 0) {
			cout << 0;
		} else {

			while (n != 0) {
				int digit = n % 10;
				cout << digit << " ";
				n = n / 10;
			}
		}
		cout << "\n";
	}

	return 0;
}