#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++) {
		int minidx = i;

		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minidx]) {
				minidx = j;
			}
		}

		swap(a[i], a[minidx]);
	}

	for (int x : a)
		cout << x << " ";
}