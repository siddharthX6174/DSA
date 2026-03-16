#include <iostream>
#include <vector>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// summation
void F(int n, int &sum, vector<int>& a) {
	if (n < 0) return;

	sum += a[n];
	F(n - 1, sum, a);
}

int main() {
	fast();

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {

		int x;
		cin >> x;

		vector<int> a(x);

		for (int j = 0; j < x; j++) {
			cin >> a[j];
		}

		int sum = 0;

		F(x - 1, sum, a);

		cout << "Case " << i << ": " << sum << "\n";
	}

	return 0;
}