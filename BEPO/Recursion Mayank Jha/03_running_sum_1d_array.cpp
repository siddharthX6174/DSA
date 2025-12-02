/*
	Solve(a,0,x): Sum of array from 0 index to x indexx.
	Solve(a,1,x): Sum of array from 1 index to x indexx.
*/

#include <iostream>
using namespace std;

int solve(int* a, int index, int x) {

	if (index == x) {
		return a[index];
	}

	int ans =  a[index] + solve(a, index + 1, x);
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