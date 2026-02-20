#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long sum{};
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		sum += a;
	}

	cout << llabs(sum) << endl;
	return 0;
}