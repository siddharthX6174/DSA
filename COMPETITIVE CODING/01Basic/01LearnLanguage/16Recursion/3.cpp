#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void F(int n) {
	if (n == 0) return;
	cout << n;
	if (n != 1) cout << " ";
	F(n - 1);
}

int main() {
	fast();
	int n;
	cin >> n;
	F(n);

	return 0;
}