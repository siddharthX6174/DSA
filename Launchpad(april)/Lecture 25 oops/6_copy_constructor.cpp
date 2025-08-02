#include<iostream>
# include <cstring>



/*
	4 Functions : Self invoked and are already there

	1. Constructor
	2. Copy Constructor
	3. Copy Assignment Operator
	4. Destructor

	1. Constructor
	2. copy consturco
*/






class Car {

private:
	// Data Members:
	int price = 100000;

public:
	char name[101] {};
	std::string company;
	int model{};
	std::string color;
	char* engine;


	// Member funcions:


	// default constructor
	// used to initialize the values
	Car() {
		std::cout << "Inside my default constructor" << std::endl;
	}


	// Constructor Overloading
	// Parameterised consturcor

	Car (char *n, std::string company, int m, std::string col, int p, char* e) {
		//name = n;

		std::cout << "Inside my parameterised constructor\n";
		std::strcpy(name, n);
		this->company = company;    // object ka jo member hai woh same name use karne k liye use kiya jata hai
		model = m;
		color = col;
		set_price(p);

		engine = new char[strlen(e) + 1];
		std::strcpy(engine, e);
	}


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
		std::cout << engine << std::endl;
		std::cout << "----------------------" << std::endl;
	}
};

int main() {
	Car e;


	//e.name = "ABC\0";
	std::strcpy(e.name, "ABC\0");
	e.company = "Tata";
	e.model = 1001;
	e.color = "Black";
	e.print();
	std::cout << e.get_price() << std::endl;
	e.set_price(30000);
	std::cout << e.get_price() << std::endl;
	std::strcpy(e.engine)



	Car f("XYZ\0", "BMW", 2003, "Red", 3400);
	f.print();

	Car g(f);
	g.print();

}