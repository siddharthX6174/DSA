# include <iostream>
# include <vector>
# include <climits>
using namespace std;

int main() {
	int n{}; // size of array
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int largest = INT_MIN;

	for (int i = 0; i < n; i++) {
		largest = max(largest, a[i]);
	}

	int secondlargest = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (a[i] != largest) {
			secondlargest = max(secondlargest, a[i]);
		}
	}

	cout << secondlargest << endl;

	return 0;
}