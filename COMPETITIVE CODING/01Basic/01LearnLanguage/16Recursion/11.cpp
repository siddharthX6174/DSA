#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int solve(int s, int e) {
	if (s > e) return 0;
	if (s == e) return 1;

	int op1 = solve(s + 1, e);
	int op2 = 0;
	if (s + 2 <= e) {
		op2 = solve(s + 2, e);
	}
	int op3 = 0;
	if (s + 3 <= e) {
		op3 = solve(s + 3, e);
	}

	return (op1 + op2 + op3);
}

int main() {
	fast();

	int s, e;
	cin >> s >> e;

	cout << solve(s, e) << "\n";

	return 0;
}