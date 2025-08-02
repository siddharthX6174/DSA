# include <iostream>
# include <algorithm>
# include <climits>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	int maxi {INT_MIN};
	int mini {INT_MAX};

	// builded pre array and taken the input of user array
	for (int i{0}; i < n; i++) {
		std::cin >> arr[i];
		pre_arr[i] = pre_arr[i - 1] + arr[i];
	}
	int pre_arr[n + 1] {};
	pre_arr[0] = arr[0];

	for (int i{1}; i < n; i++) {
		pre_arr[i] = pre_arr[i - 1] + arr[i];
		maxi = std::max(maxi, pre_arr[i]);
		mini = std::min(mini, pre_arr[i]);
	}


	// freq array now
	int freq_arr [maxi - mini + 1] {};
	for (int i{}: i < n; i++) {
		int curr_ele = pre_arr[i];

		if (freq_arr[curr_ele - mini] == 0) {
			std::cout << "yes" << std::endl;
			return 0;
		}

		if ((((curr_ele + mini) - 0) > 0) and freq_arr[curr_ele + mini - 0] > 0) {
			cout << "YES" << endl;
			return 0;
		}

		freq_arr[curr_ele] += 1;
	}

	std::cout << "NO" << std::endl;
	return 0;
}