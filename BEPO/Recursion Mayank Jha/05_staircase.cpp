#include<iostream>
using namespace std;

//Solve(0,x): Total ways to reach the xth stair from 0th stair.
//Solve(1,x): Total ways to reach the xth stair from 1th stair.
//Solve(i,x): Total ways to reach the xth stair from ith stair.

int solve(int i, int x) {

	if (i == x) {
		return 1;
	}

	int op1 = solve(i + 1, x);
	int op2 = 0;
	if (i + 2 <= x) {
		op2 = solve(i + 2, x);
	}
	return (op1 + op2);
}

int main() {
	int n{};
	cin >> n;

	cout << solve(0, n) << endl;
	return 0;
}