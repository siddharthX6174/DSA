#include<iostream>
using namespace std;

int main() {
	int n{}, m{};
	cin >> n >> m;

	int a[100][100] {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int k{};
	cin >> k;

	bool ans{0};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (k == a[i][j]) {
				ans = 1;
			}
		}
	}

	if (ans) {
		cout << "will not take number";
	} else {
		cout << "will take number";
	}

	return 0;

}