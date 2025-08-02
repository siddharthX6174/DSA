# include <iostream>
# include <algorithm>

int main() {
	int a{}, b{};
	std::cin >> a >> b;

	int n{std::min(a, b)};
	int ans{};

	while (n > 0) {
		if ((a % n == 0) and (b % n == 0)) {
			ans = n;
			break;
		}
		n--;
	}

	std::cout << ans << std::endl;

	return 0;
}