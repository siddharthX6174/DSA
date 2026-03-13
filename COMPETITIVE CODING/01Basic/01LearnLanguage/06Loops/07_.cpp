#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	bool yes = false;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			cout << i << "\n";
			yes = true;
		}
	}
	if (yes == false) {
		cout << -1;
	}
	return 0;
}