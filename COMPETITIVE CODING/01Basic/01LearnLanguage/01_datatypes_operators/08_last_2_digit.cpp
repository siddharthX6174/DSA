#include <iostream>
using namespace std;

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;

	long long result = 1;
	result = (result * (a % 100)) % 100;
	result = (result * (b % 100)) % 100;
	result = (result * (c % 100)) % 100;
	result = (result * (d % 100)) % 100;

	if (result < 10) cout << 0;
	cout << result << endl;

	return 0;
}
