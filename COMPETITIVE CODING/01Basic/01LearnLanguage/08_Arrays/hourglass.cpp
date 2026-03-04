#include <iostream>
#include <climits>
using namespace std;

int main() {
	int a[6][6];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> a[i][j];
		}
	}

	int maxi = INT_MIN;

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			int sum = 0;
			// top row
			sum += a[i][j];
			sum += a[i][j + 1];
			sum += a[i][j + 2];

			// middle
			sum += a[i + 1][j + 1];

			// bottom row
			sum += a[i + 2][j];
			sum += a[i + 2][j + 1];
			sum += a[i + 2][j + 2];

			maxi = max(maxi, sum);
		}
	}

	cout << maxi << endl;
	return 0;
}