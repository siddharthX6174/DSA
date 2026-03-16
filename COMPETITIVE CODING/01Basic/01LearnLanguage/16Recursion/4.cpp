#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long F(int n) {
	if (n == 0 or n == 1) return 1;
	return n * F(n - 1);
}
int main() {
	fast();

	int n;
	cin >> n;
	cout << F(n);

	return 0;
}