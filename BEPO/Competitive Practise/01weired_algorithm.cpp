#include<iostream>
using namespace std;

int main() {
	long long n{};
	cin >> n;
	cout << n << " ";

	while (n != 1) {
		if (n % 2 == 0) {
			// he algorithm divides it by two
			n = n / 2;
			cout << n << " ";
		} else {
			//algorithm multiplies it by three and adds one
			n = (n * 3) + 1;
			cout << n << " ";
		}

		//The algorithm repeats this, until n is one
	}
	return 0;
}