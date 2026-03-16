#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void F(int n, int* a) {
	if (n == 0) return;
	if (n % 2 != 0) {
		cout <<  a[n] << " ";
	}
	F(n - 1, a);
}

int main() {
	fast();

	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];

	F(n, a);

	return 0;
}