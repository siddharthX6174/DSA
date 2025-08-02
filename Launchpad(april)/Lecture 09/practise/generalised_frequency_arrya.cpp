# include <iostream>
# include <algorithm>
# include <climits>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	int maxi {INT_MIN};
	int mini {INT_MAX};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
		maxi = std::max(maxi, arr[i]);
		mini = std::min(mini, arr[i]);
	}

	// frequency array build
	int freq_arr [maxi - mini + 1] {};
	for (int i{}; i < n; i++) {
		freq_arr [arr[i] - mini] ++;
	}

	// printing frequencies
	for (int i{}; i < maxi - mini + 1; i++) {
		if (freq_arr[i] != 0) {
			std::cout << i + mini << "  -->  " << freq_arr[i] << std::endl;
		}
	}

	return 0;


}