# include <iostream>

// pass by value

void check (int a, int b) {
	std::cout << "Inside My function check" << std::endl;
	std::cout << a << " " << b << std::endl;

	a += 10;
	b -= 7;

	std::cout << a << " " << b << std::endl;

	return ;
}

// pass by Address to channge the value
void check2 (int* a, int* b) {
	std::cout << "Inside My function check" << std::endl;
	std::cout << *a << " " << *b << std::endl;

	*a += 10;
	*b -= 7;

	std::cout << *a << " " << *b << std::endl;

	return ;
}



int main() {
	int a, b;
	std::cin >> a >> b;

	std::cout << "Inside main" << std::endl;
	std::cout << a << " " << b << std::endl;

	check(a, b);

	check2(&a, &b);

	std::cout << a << " " << b << std::endl;

	return 0;
}