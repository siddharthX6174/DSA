# include <iostream>

int main() {
	int n{};
	std::cin >> n;
	int nums[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> nums[i];
	}

	// decreasing the array by 1 so that calculation becomes easy ffurther
	for (int i{}; i < n; i++) {
		nums[i]--;
	}

	// go to correct positoon and add n for storing frequency in original array
	for (int i{}; i < n; i++) {
		nums[nums[i] % n] += n;
	}

	// taking out the correct output as reguired i have to print the elements of freq 2
	for (int i{}; i < n; i++) {
		if (nums[i] / n == 2) {
			std::cout << i + 1 << ", ";
		}
	}

	return 0;


}