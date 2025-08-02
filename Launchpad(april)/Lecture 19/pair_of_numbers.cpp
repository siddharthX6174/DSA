
#include<iostream>
#include<climits>

int n{};


int F(int a, int b) {

	if (a > n or b > n) {
		return 1e8;
	}

	if (a == n or b == n) {
		return 0;
	}

	int op1 = 1 + F(a + b, b);
	int op2 = 1 + F(a, a + b);

	// Then what is the answer for F(a,b);

	return std::min(op1, op2);
}

int main() {
	std::cin >> n;

	std::cout << F(1, 1) << std::endl;
}