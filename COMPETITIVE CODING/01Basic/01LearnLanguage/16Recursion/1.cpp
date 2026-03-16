#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


void F(int i, int n) {
	if (i == n) return;
	cout << "I love Recursion\n";
	F(i + 1, n);
}

int main() {
	fast();
	int n;
	cin >> n;

	F(0, n);

	return 0;
}