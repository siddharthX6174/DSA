// n(n+1)/2;
#include<iostream>
using namespace std;

int main() {
	long long n{};
	cin >> n;

	n = (long long)((n * (n + 1)) / 2);

	cout << n << "\n";
	return 0;
}