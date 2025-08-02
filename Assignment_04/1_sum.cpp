# include <iostream>

// 1<=n<=10^5
// 1<=q<=10^5

// computations = ~ (n*q)
// worst case computations : ~(10^10)

// 1 sec = 10^8
// 100 sec = 10^10







int main() {
	int n{};
	std::cin >> n;

	int a[n] {};
	for (int i{}; i < n; i++) (std::cin >> a[i]);

	int q{};
	std::cin >> q;

	int l{}, r{};
	int computations{};

	while (q > 0) {
		int ans{};
		std::cin >> l >> r;
		for (int i{l}; i <= r; i++) {
			computations++;
			ans += a[i];
		}
		std::cout << ans << std::endl;

		q -= 1;
	}
	std::cout << computations << std::endl;
	return 0;
}