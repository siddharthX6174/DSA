#include<iostream>
using namespace std;
int target;

int solve(int x, int y) {

	if (x > target or y > target) {
		// return something so big that can never be your answer..
		return 1e5;
	}

	if (x == target or y == target) {
		return 0;
	}

	int op1 = solve(x + y, y) + 1;
	int op2 = solve(x, x + y) + 1;
	return min(op1, op2);
}

int main() {
	cin >> target;
	int ans = solve(1, 1);
	cout << ans << endl;
	return 0;
}