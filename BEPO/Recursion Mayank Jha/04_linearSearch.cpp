
/*
	F(n) = check key is present from 0 to n-1 index.
	g(n) = check key is present from 1 to n-1 index.
*/


#include <iostream>
using namespace std;

bool solve(int* a, int index, int x, int key) {

	if (index == x) {
		return a[index] == key;
	}

	bool ans = (a[index] == key) or solve(a, index + 1, x, key);
	return ans;
}

int main() {
	int n;
	cin >> n;

	int a[n] {};

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int key{};
	cin >> key;
	cout << solve(a, 0, n - 1, key);
}
