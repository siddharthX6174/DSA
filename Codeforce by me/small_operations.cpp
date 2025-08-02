# include <iostream>

int main() {

	int x{}, y{}, k{};
	std::cin >> x >> y >> k;

	for (int i{1}; i <= k; i++) {
		int a = i;
		int ans{};

		if (x < y) {
			x =  x * a;
			ans++;
		} else if (x > y) {
			x = x / a;
			ans++;
		} else {
			std::cout << ans;
			return 0;
		}
	}
	std::cout << -1;
	return 0;

}