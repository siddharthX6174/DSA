#include<iostream>
using namespace std;

class OrderBuilder {
public:
	int exchange_id;
	string exchange_name;
	OrderBuilder(string name, int id) {
		exchange_name = name;
		exchange_id = id;
	}
};

class Strategy {
private:
	double order_qty;
	double price;
	string user_name;
	OrderBuilder* ob;
public:

	Strategy(double qty, double prc, string name) : order_qty(qty), price(prc), user_name(name) {
		cout << "Inside Constructor\n";
		OrderBuilder* obj = new OrderBuilder("CME", 107);
		ob = obj;
	};

	Strategy(const Strategy& obj) {
		cout << "own deepy copy Constructor invoked\n";
		order_qty = obj.order_qty;
		price = obj.price;
		user_name = obj.price;
		ob = new OrderBuilder(obj.ob->exchange_name, obj.ob->exchange_id);
	}

	~Strategy() {
		cout << "destructor called\n";
		delete ob;
	}

	void PrintStrategy() {
		cout << "order quantity : " << order_qty << "\n";
		cout << "Price : " << price << "\n";
		cout << "Username : " << user_name << "\n";
		cout << "Exchange name : " << ob->exchange_name << "\n";
	}
};

int main() {

	Strategy* obj1 = new Strategy(10, 100.0, "karan");
	obj1->PrintStrategy();

	Strategy obj2(*obj1);
	delete obj1;
	obj2.PrintStrategy();
	return 0;
}