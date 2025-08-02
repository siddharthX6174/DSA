# include <iostream>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	// build pre array
	int pre_arr [n + 1] {};
	pre_arr[0] = arr[0];

	for (int i{1}; i < n; i++) {
		pre_arr[i] = pre_arr[i - 1] + arr[i];
	}


	// caluculate sum form lower range to uper range for the q queris

	int q{};
	std::cin >> q;
	while (q--) {
		int l{}, r{};
		std::cin >> l >> r;

		int sum{};

		if (l == 0) { sum = pre_arr[r]; }
		else {
			sum = pre_arr[r] - pre_arr [l - 1];
		}

		std::cout << "sum[" << l << "," << r << "] = " << sum << std::endl;
	}

	return 0;
}