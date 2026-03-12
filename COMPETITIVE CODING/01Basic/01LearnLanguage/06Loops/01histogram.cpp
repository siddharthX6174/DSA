#include<iostream>
using namespace std;

int main() {
	char c;
	cin >> c;

	int n;
	cin >> n;

	while (n--) {
		int x;
		cin >> x;

		for (int i = 0; i < x; i++) {
			cout << c;
		}
		cout << "\n";
	}

	return 0;
}