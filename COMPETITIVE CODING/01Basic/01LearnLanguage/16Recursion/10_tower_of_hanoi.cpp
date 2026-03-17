#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long countMoves(int n) {
	if (n == 1) return 1;
	return 2 * countMoves(n - 1) + 1;
}

void solve(int n, int from, int to, int aux) {

	if (n == 0) return;

	solve (n - 1, from, aux, to);
	cout << from << " " << to << "\n";

	solve(n - 1, aux, to, from);
}

int main() {
	fast();

	int n;
	cin >> n;

	cout << countMoves(n) << "\n";

	solve(n, 1, 3, 2);

	return 0;
}