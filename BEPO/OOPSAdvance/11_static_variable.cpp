#include<bits/stdc++.h>
using namespace std;

/*
	static keyword:

	1. Static variable
	 * Represents the property of a class which is common for all the objects
	 * Variables are assigned memory in the static storage area but not in heap
	 * These are not associated with the instance of the class

	2. Static function
	 * Can be called without creating the object
	 * Can only access the static member variables of the class
	 * Memory is not assigned in the heap area instead of static storage area
	 * These are not associated with the instance of the class
*/

class Strategy {
	int order_qty;
	static string company_name;
	static int strategy_count;
public:
	Strategy(int qty) : order_qty(qty) {
		cout << "Constructor called\n";
	}

	void PlaceOrder() {
		cout << "placing the order in the market : \n";
		strategy_count++;
	}

	void DisplayTotalStrategies() {
		cout << "Total Strategies in the market: " << strategy_count << endl;
	}

	static void DisplayCompanyName() {
		//cout << "orderqty : " << order_qty << "\n";
		cout << "company_name : " << Strategy::company_name << "\n";
	}
	void DisplayQty() {
		cout << "orderqty : " << order_qty << "\n";
	}
};

string Strategy::company_name = "GoldManSachs";
int Strategy::strategy_count = 0;

int main() {
	Strategy obj(10);
	obj.DisplayQty();
	//obj.DisplayCompanyName();
	Strategy::DisplayCompanyName();


	//Strategy::DisplayQty();

	Strategy obj2(100);
	obj2.PlaceOrder();
	obj2.DisplayTotalStrategies();


	return 0;
}