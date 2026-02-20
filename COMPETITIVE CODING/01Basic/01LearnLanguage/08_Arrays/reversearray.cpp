#include<iostream>
using namespace std;

int main() {
	int n{};
	cin >> n;

	int a[n] {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int i = 0;
	int j = n - 1;

	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}

	for (auto x : a) {
		cout << x << " ";
	}

	return 0;
}