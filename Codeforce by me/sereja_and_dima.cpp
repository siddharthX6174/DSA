# include <iostream>
# include <algorithm>

int main() {
	int n{};
	std::cin >> n;
	int a[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> a[i];
	}

	int s_sum{}, d_sum{};
	/*int i = 0, j = n - 1;

	while (i <= j) {
		if (a[i] > a[j]) {
			s_sum += std::max(a[i], a[j]);
			i++;
		} else {
			s_sum += std::max(a[i], a[j]);
			j--;
		}

		if (a[i] > a[j]) {
			d_sum += std::max(a[i], a[j]);
			i++;
		} else {
			d_sum += std::max(a[i], a[j]);
			j--;
		}

	}*/

	int left = 0, right = n - 1;
	int trun = 0;

	while (left <= right) {
		// seerja sum
		if (turn % 2 == 0) {
			if (a[left] > a[right]) {
				s_sum += a[length];
				left++;
			}
		} else {
			s_sum += a[right];
			right--;
		}
	}

	std::cout << s_sum << " " << d_sum;

	return 0;

}