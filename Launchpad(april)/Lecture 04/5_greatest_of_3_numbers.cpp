# include <iostream>


int main() {

	/*
		Airthmetic Operators : +,-,/,*,%
		Relation Operators : >,<, >=, <=, ==
		Assignment Operators : +=, -=, *=, /=, =

		Logival Operators : and(&&), or(||), not(!)
	*/

	int a{}, b{}, c{};
	std::cin >> a >> b >> c;

	if ((a > b) && (a > c)) {
		std::cout << a << std::endl;
	} else if ((b > c) && (b > a)) {
		std::cout << b << std::endl;
	} else {
		std::cout << c << std::endl;
	}


	return 0;
}