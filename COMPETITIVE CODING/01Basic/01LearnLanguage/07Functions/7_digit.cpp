#include<iostream>
using namespace std;

int ds(int i) {
	int s{};
	while (i > 0) {
		s += i % 10;
		i = i / 10;
	}
	return s;
}

int main() {
	int n{}, a{}, b{};
	cin >> n >> a >> b;

	int sum{};
	for (int i = 1; i <= n; i++) {
		int d = ds(i);
		if (d >= a and d <= b) sum += i;
	}
	cout << sum << "\n";
	return 0;
}