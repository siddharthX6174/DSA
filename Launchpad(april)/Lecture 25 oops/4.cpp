#include<iostream>
# include <cstring>

class Car {

private:
	// Data Members:
	int price = 100000;

public:
	char name[101] {};
	std::string company;
	int model{};
	std::string color;


	// Member funcions:


	// Getter
	int get_price () {
		return price;
	}

	// Setter
	void set_price(int discount_price) {
		if (discount_price < 45000) {
			price = 45000;
		} else {
			price = discount_price;
		}
	}

	void print () {
		std::cout << "-----------------------" << std::endl;
		std::cout << name << std::endl;
		std::cout << company << std::endl;
		std::cout << model << std::endl;
		std::cout << price << std::endl;
		std::cout << color << std::endl;
		std::cout << "----------------------" << std::endl;
	}
};

int main() {
	Car e;
	std::cout << sizeof(Car) << std::endl;
	std::cout << sizeof(e) << std::endl;
	std::cout << sizeof(int) << std::endl;


	//e.name = "ABC\0";
	std::strcpy(e.name, "ABC\0");
	e.company = "Tata";
	e.model = 1001;
	e.color = "Black";

	// e.price = 897; Error will there
	e.print();


	std::cout << e.get_price() << std::endl;
	e.set_price(30000);

	std::cout << e.get_price() << std::endl;
}