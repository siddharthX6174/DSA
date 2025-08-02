# include <iostream>
# include <climits>
# include <algorithm>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	int maxi = INT_MIN;
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
		maxi = std::max(maxi, arr[i]);
	}

	// normal frequenxy array
	int freq [maxi + 1] {};
	for (int i{}; i < n; i++) {
		freq [arr[i]] += 1;
	}

	// print the frequency
	for (int i{}; i < maxi + 1; i++) {
		if (freq[i] > 0) {
			std::cout << i << " = " << freq[i] << ",  ";
		}
	}
	std::cout << std::endl;

	return 0;
}