# include <iostream>
# include <cstring>
const int N = 0;

/*
	SELF INVOKED METHODS

	constructor
	copy constructor
	copy assignment operator
	destructor
*/


class Car {
private:
	int price = 1000;
public:
	int model{};
	std::string condition;
	double mileage;
	char Name[100];



	void set_price (double discount) {
		if (discount < 15) {
			price = 1000 * (1 - (double)(discount / 100));
		} else {
			price = 850;
		}
	}

	int get_price () {
		return price;
	}


	// constructor
	// parameterised constructor
	Car (int model, std::string c, double mileage, char* n, double discount) {
		this->model = model;
		condition = c;
		this->mileage = mileage;
		std::strcpy(Name, n);
		set_price(discount);
	}

	void print() {
		std::cout << model << std::endl;
		std::cout << condition << std::endl;
		std::cout << mileage << std::endl;
		std::cout << Name << std::endl;
		std::cout << price << std::endl;
	}
};


int main() {
	Car c(122, "Very Good", 105.8, "BMW", 5);
	c.print();

}