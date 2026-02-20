#include<iostream>
using namespace std;
#include<vector>

int main() {
	vector<int> fib(46);
	fib[1] = 0;
	fib[2] = 1;

	int n;
	cin >> n;


	int a = 0;
	int b = 1;

	if (n == 1) {
		cout << a << " ";
	} else if (n == 2) {
		cout << a << " " << b << " ";
	} else {
		cout << a << " " << b << " ";
		for (int i = 3; i <= n; i++) {
			int c = a + b;
			cout << c << " ";
			a = b;
			b = c;
		}
	}
	return 0;
}