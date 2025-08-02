#include<iostream>
#include <algorithm>

const int N = 1e5 + 10;
int n{}, k{};
int taste[N], calorie[N];

int F(int i, int sum) {
	if (i == n) {
		// check if this is a valid path or not
		if (sum == 0) {
			// This i sa valid paht
			return 0;
		}

		return -1e8;
	}

	// Choose the current fruit .
	int op1 = taste[i] + F(i + 1, sum + taste[i] - k * calorie[i]);
	// dont chooes the curent fruit
	int op2 = 0 + F(i + 1, sum);

	return std::max(op1, op2);
}

int main() {
	std::cin >> n >> k;
	for (int i{}; i < n; i++) {
		std::cin >> taste[i];
	}
	for (int i{}; i < n; i++) {
		std::cin >> calorie[i];
	}

	int ans = F(0, 0);

	if (ans <= 0) {
		std::cout << -1 <<  std::endl;
	} else {
		std::cout << ans << std::endl;
	}

}