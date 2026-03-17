#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


bool solve(long long i, long long n) {
	if (i > n) return false;
	if (i == n) return true;

	return (solve(i * 10, n) or solve(i * 20, n));
}

int main() {
	fast();

	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		bool ans = solve(1, n);

		if (ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}