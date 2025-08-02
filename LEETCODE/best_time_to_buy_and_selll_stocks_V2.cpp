# include <iostream>
# include <algorithm>


int main() {
	int n{};
	std::cin >> n;
	int prices [n] {};
	for (int i{}; i < n; i++) {
		std::cin >> prices[i];
	}

	int max_future_prices[n] {};
	max_future_prices[n - 1] = prices [n - 1];
	// Step 1: Fill maxFuturePrice from right to left
	for (int i = n - 2; i >= 0; i--) {
		max_future_prices[i] = std::max(prices[i], max_future_prices[i + 1]);
	}

	// Step 2: Calculate the max profit
	int max_profit {};
	for (int i{}; i < n - 1; i++) {
		int profit = max_future_prices[i + 1] - prices[i];
		max_profit = std::max(max_profit, profit);
	}

	std::cout << max_profit;
}