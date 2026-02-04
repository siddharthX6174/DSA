#include<iostream>
using namespace std;

class Strategy {
public:
	int orderqty;
	void PrintOrderQty() {
		cout << "order quantity = " << orderqty << endl;
	}
};

int main() {
	// automatic storage allocation..
	Strategy obj;
	obj.orderqty = 10;
	obj.PrintOrderQty();

	// dynamic storage allocation
	Strategy* obj1 = new Strategy();
	obj1->orderqty = 20;
	obj1->PrintOrderQty();
	(*obj1).PrintOrderQty();  // value at / dereference operator...

	delete obj1;
	return 0;
}