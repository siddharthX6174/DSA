#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void F(int n) {
	if (n == 1) {
		return;
	}

	if (n % 2 == 0) {
		n = n / 2;
	} else {
		n = (n * 3) + 1;
	}
	cout << n << " ";
	F(n);

}
int main() {
	fast();

	int n;
	cin >> n;
	cout << n << " ";
	F(n);

	return 0;
}