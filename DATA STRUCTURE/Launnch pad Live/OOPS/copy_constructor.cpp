# include <iostream>
# include <cstring>
const int N = 0;

/*
	copy constructor
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


	// copy constructoe
	Car (Car &l) {
		std::cout << "you are inside your own copy instructor\n" ;
		model = l.model;
		condition = l.condition;
		mileage = l.mileage;
		std::strcpy(Name, l.Name);
		price = l.price;
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
	std::cout << "------------\n";

	// default copy constuctor is invoked (which do shallow copy)
	Car e(c);

	// Shallow and deep copy concept comes into role paly
	e.print();

}