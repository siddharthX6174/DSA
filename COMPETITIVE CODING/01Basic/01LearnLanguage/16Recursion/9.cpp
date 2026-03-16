#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void F(int i, int j, int* a, bool& k) {
	if (i > j) return;
	k = k and (a[i] == a[j]);
	F(i + 1, j - 1, a, k);
}
int main() {
	fast();

	int n;
	cin >> n;
	int a[n] {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 0, j = n - 1;
	bool k = true;
	F(i, j, a, k);
	if (k) cout << "YES\n";
	else cout << "NO\n";


	return 0;
}