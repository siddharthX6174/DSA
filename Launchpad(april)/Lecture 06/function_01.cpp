# include <iostream>
# include "mayank.h"
# include "../Lecture 05/samyak.h"

int sum(int, int);    // function prototype ..... by this stack can recognize this name but memory space will not be used in the stack...
int difference(int, int);

int main() {
	int x{}, y{};
	std::cin >> x >> y;
	std::cout << sum(x, y) << std::endl << difference(x, y) << std::endl;
	check();
	check1();

	return 0;
}


int sum (int a, int b) {
	return a + b;
}

int difference (int a, int b) {
	return a - b;
}