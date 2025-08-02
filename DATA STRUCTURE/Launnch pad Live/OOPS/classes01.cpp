# include <iostream>


// user defined data-type
class Car {
	// TO access the private data members and member functions we have getters and setters
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

	void print() {
		std::cout << model << std::endl;
		std::cout << condition << std::endl;
		std::cout << mileage << std::endl;
		std::cout << Name << std::endl;
		std::cout << price << std::endl;
	}
};


int main() {
	Car c;  // this is an object (it will have all the functionnality of the data type car.)
	// this can access all the public member or memeber functions of the class car.
	// we access using the . operator
	// c.mileage ---- it will be specific to c only

	c.model = 122;
	c.condition = "Very Good";
	c.mileage = 105.3;
	//c.Name = "BMW";
	c.Name[0] = 'B';
	c.Name[1] = 'M';
	c.Name[2] = 'W';
	c.Name[3] = '\0';
	//c.price = 100;

	c.print();
	// std::cout << c.model << std::endl;
	// std::cout << c.condition << std::endl;
	// std::cout << c.mileage << std::endl;
	// std::cout << c.Name << std::endl;
	// std::cout << c.price << std::endl;

	c.set_price(9);
	std::cout << "-----------------\n";
	std::cout << c.get_price() << std::endl;

}