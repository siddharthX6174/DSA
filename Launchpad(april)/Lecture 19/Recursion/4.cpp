// nth number in fibonacci serires
// nth number is the sum of previous n-1 term + n-2 term

# include <iostream>

int fibb(int x) {


	if (x == 0) return 0;
	if (x == 1) return 1;

	return fibb(x - 1) + fibb(x - 2);

}


int main() {
	int n{};
	std::cin >> n;

	std::cout << fibb(n);
}