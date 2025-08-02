#include<iostream>

class Car {
private:
	int price = 500;

public:
	int model{};
	std::string name;


	// default constructor -----
	Car() {
		std::cout << "default constructor was called.\n";
	}


// -------------------------------------------------------------------------------------------------------
	void set_price (int x) {
		if (x > 200) {
			price = x;
		} else {
			std::cout << "Can't update the new price it lies outside the constraint.\n";
		}
	}

	int get_price () {
		return price;
	}

	void print_car_behaviour () {
		std::cout << "-----------\n";
		std::cout << price << std::endl;
		std::cout << model << std::endl;
		std::cout << name << std::endl;
		std::cout << "-------------\n";
	}
};
//-------------------------------------------------------------------------------------------------------


int main() {

	Car a ;
	a.model = 10001;
	a.name = "BMW";
	//a.set_price(100);

	std::cout << a.get_price() << std::endl;



	return 0;

}