#include<iostream>
using namespace std;

// public:
// class Strategy {
// public:
// 	double qty;
// 	double price;

// 	void PrintPriceQty() {
// 		cout << "quantity : " << qty << "\n";
// 		cout << "price : " << qty << "\n";
// 	}
// };

// private:

// class Strategy {
// private:
// 	double qty;
// public:
// 	double price;

// 	void PrintPriceQty() {
// 		cout << "quantity : " << qty << "\n";
// 		cout << "price : " << price << "\n";
// 	}
// };

class Strategy {
protected:
	double qty;
public:
	double price;

	void PrintPriceQty() {
		cout << "quantity : " << qty << "\n";
		cout << "price : " << price << "\n";
	}
};


int main() {
	//dynamic
	Strategy* obj1 = new Strategy();
	// obj1->qty
	//(*obj1).qty = 10;
	(*obj1).price = 100;
	(*obj1).PrintPriceQty();
	delete obj1;

	return 0;
}