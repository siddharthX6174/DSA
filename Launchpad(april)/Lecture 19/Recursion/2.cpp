// find the factorial

# include <iostream>

int fact(int x) {
	// base
	if (x == 0) {
		return 1;
	}

	int ans = x * fact(x - 1);

	return ans;
}



int main() {
	int n{};
	std::cin >> n;

	std::cout << fact(n);
}