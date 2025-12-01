// check if the array is sorted or not
/*
	F(n) -> check if array is sorted from 0 to n-1 index.
	G(n) -> check if array is sorted from 1 to n-1 index.
	h(n) -> check if array is sorted from 2 to n-1 ineex.

	stoping point -> if n >= n-1
*/
#include <iostream>
using namespace std;

bool solve(int* a, int index, int x) {

	if (index == x) {
		return true;
	}

	bool ans = (a[index] < a[index + 1]) and solve(a, index + 1, x);
	return ans;
}

int main() {
	int n;
	cin >> n;

	int a[n] {};

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << solve(a, 0, n - 1);
}

