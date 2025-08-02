#include <iostream>
#include <algorithm>

int main() {
	int t{};
	std::cin >> t;

	for (int i{}; i < t; i++) {
		int n{}, x{};
		std::cin >> n >> x;

		int a, prev_station = 0, max_bw_gas = 0;

		for (int j = 0; j < n; j++) {
			std::cin >> a;
			max_bw_gas = std::max(max_bw_gas, a - prev_station);
			prev_station = a;
		}

		// Final segment: from last gas station to x
		max_bw_gas = std::max(max_bw_gas, 2 * (x - prev_station));

		std::cout << max_bw_gas << std::endl;
	}

	return 0;
}
