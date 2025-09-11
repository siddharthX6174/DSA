#include <iostream>
using namespace std;

// solve(a,0,n-1): sum of array elments from 0 to n-1;
// solve(a,1,n-1): sum of array elements from 1 to n-1;

// solve(a,0,n-1) = a[0] + solve(a,1,n-1);
// solve(a,i,n-1) = a[i] + solve(a,i+1, n-1);

int solve(int* a, int i, int x) {
	//base
	if (i == x) {
		return a[x];
	}
	// task
	int sum = a[i] + solve(a, i + 1, x);
	return sum;
}

int main() {
	int n{};
	cin >> n;

	int a[n] {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// fn
	cout << solve(a, 0, n - 1) << endl;
	return 0;
}