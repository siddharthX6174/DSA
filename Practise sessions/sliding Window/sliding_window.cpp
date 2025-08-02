# include <iostream>
# include <climits>
# include <algorithm>

int main() {
	int arr[] {10, 22, 56, 78, 8, 32, 64, 98, 45, 56};
	int n = 10;
	int k = 3;

	// sliding algo

	int window_sum {0};
	int ans {INT_MIN};

	for (int i{}; i < k; i++) {
		window_sum += arr[i];
	}

	ans = std::max(window_sum, ans);

	// move the window and find the max...
	for (int i = k; i < n; i++) {
		window_sum = window_sum + arr[i] - arr[i - k];

		ans = std::max(window_sum, ans);
	}

	std::cout << ans << std::endl;
}