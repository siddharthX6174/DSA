# include <iostream>
# include <climits>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}


	// build run_summing array
	int pre_arr[n + 1] {};
	pre_arr[0] = arr[0];
	for (int i{1}; i < n; i++) {
		pre_arr[i] = pre_arr[i - 1] + arr[i];
	}

	for (int i{}; i < n; i++) {
		std::cout << pre_arr[i] << " ";
	}
	std::cout << std::endl;

	int q{}; // queries
	std::cin >> q;

	int l{}, r{}, sum{}; // lower range and upper range;

	while (q > 0) {

		std::cin >> l >> r;

		if (l == 0) {
			sum = pre_arr[r];
		} else {
			sum = pre_arr[r] - pre_arr[l - 1];
		}

		std::cout << "Sum_arr [" << l << ", " << r << "]  =  " << sum << std::endl;


		q--;
	}

	return 0;

}