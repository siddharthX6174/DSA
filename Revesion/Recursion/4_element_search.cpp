#include<iostream>
using namespace std;

// search an element inside a array and yes or no if found or not found

// check if elemment if present from 0 to n-1
// check if elementt if present form 1 to n-1

bool is_present(int*a, int i, int x, int target) {

	if (i == x) {
		return (a[x] == target);
	}

	//task
	int ans = (a[i] == target) or is_present(a, i + 1, x, target);
	return ans;
}


int main() {
	int n{};
	cin >> n;

	int a[n] {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int target{};
	cin >> target;

	// fn
	cout << is_present(a, 0, n - 1, target) << endl;
	return 0;
}