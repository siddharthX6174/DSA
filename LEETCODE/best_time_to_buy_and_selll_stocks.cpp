# include <iostream>
# include <algorithm>


int main() {
	int n{};
	std::cin >> n;
	int prices [n] {};
	for (int i{}; i < n; i++) {
		std::cin >> prices[i];
	}

	int ans {};
	for (int i{}; i < n - 1; i++) {
		int possible_ans {};
		for (int j = i + 1; j < n; j++) {
			if (prices[i] < prices[j]) {
				possible_ans = prices[j] - prices[i];
				ans = std::max(ans, possible_ans);
			}
		}
	}

	std::cout << ans << std::endl;
	return 0;
}