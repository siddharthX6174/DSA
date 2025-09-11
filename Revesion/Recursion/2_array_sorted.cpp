// check if the array is sorted or not

#include <iostream>
using namespace std;

// check(a,0,n-1) - check if the arry is soted form 0 to n-1
// chceck(a, 1, n-1) - check if the array is sorted from 1 to n-1.

bool check(int* a, int i, int x) {

	if (i == x) {
		// single element sorted hota hai ..
		return true;
	}

	//task
	bool ans = (a[i] < a[i + 1]) and check(a, i + 1, x);
	return ans;
}

int main() {
	int n{};
	cin >> n;

	int a[n] {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// fn
	cout << check(a, 0, n - 1) << endl;
	return 0;
}