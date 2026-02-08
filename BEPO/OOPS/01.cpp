#include<bits/stdc++.h>
using namespace std;

/*
	To access the Private data members and member Functions
	on your terms we have Getters and Setters.
*/
class Car {
private:
	int Price = 1000;
public:
	int Model;
	string Condition;
	double Mileage;
	char Name[100];

	// Default Constructor
	Car() {
		cout << "Default Constructor" << endl;
	}

	// you can make your own parameterised constructor Car() pass variables in it
	// Constructor Overloading

	// making my own copy constrcutor
	Car(Car &l) {
		Price = l.Price;
		Model = l.Model;
		Condition = l.Condition;
		Mileage = l.Mileage;
		strcpy(Name, l.Name);
	}

	// setters
	void Set_Price(double discount) {
		if (discount < 15) {
			Price = 1000 * (1 - (double)discount / 100);
		} else {
			Price = 850;
		}
	}

	// Getters
	int  Get_Price() {
		return Price;
	}

	void print() {
		cout << Model << "\n";
		cout << Price << "\n";
		cout << Condition << "\n";
		cout << Mileage << "\n";
		cout << Name << "\n";
		cout << "-----------------------------\n";
	}
};

int main() {

	int x;
	// Object takes space in memory not the class one
	Car c;//This is an object (It will have all the functionality of the data type Car)

	c.Model = 144;
	c.Condition = "very good";
	c.Mileage = 105.8;
	c.Name[0] = 'B';
	c.Name[1] = 'M';
	c.Name[2] = 'W';
	c.Name[3] = '\0';

	c.print();

	c.Set_Price(9);
	cout << c.Get_Price() << endl;
	cout << "-------------\n";

	Car f(c);
	f.print();

	return 0;
}

/*
	1. Constructor
	2. Copy Constructor
	3. Copy Assignment Operator
	4. Destructor
*/