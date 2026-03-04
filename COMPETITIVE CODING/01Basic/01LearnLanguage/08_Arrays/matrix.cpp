#include<iostream>
using namespace std;


int main() {
	int n{};
	cin >> n;
	int a[101][101] {{}};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// process primary diagonal
	int pri{};
	for (int i = 0; i < n; i++) {
		pri += a[i][i];
	}

	// process seconday diagronal
	int sec{};
	for (int i = 0; i < n; i++) {
		sec += a[i][n - 1 - i];
	}

	cout << abs(pri - sec);
	return 0;
}