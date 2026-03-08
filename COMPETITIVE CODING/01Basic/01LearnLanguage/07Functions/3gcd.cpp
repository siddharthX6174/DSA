#include<iostream>
using namespace std;

int f(int a, int b) {
	int mini = min(a, b);
	int ans = 1;
	for (int i = 1; i <= mini; i++) {
		if (a % i == 0 and b % i == 0) {
			ans = i;
		}
	}
	return ans;
}

int main() {
	int a{}, b{};
	cin >> a >> b;

	cout << f(a, b);

	return 0;
}