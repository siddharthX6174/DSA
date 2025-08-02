// calculate suum of n nums

# include <iostream>

int F(int x) {

	if (x == 1) {
		return 1;
	}

	int ans = x + F(x - 1);
	return ans;
}

int main() {
	int n{};
	std::cin >> n;

	std::cout << F(n);
}