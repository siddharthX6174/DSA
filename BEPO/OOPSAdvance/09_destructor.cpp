#include<bits/stdc++.h>
using namespace std;

/*
	Destructor
		In c++, destructor is a special memebr function of a class that is executed
		when an object of that class is destroyed. The primary purpose of a destructor
		is to release resources that the object may have accquired durring
		its lifetime..
		This includes deallocating memory, closing files, and releasing
		network resources, among other cleanup tasks.

		1. Memory management without new
		2. Memory Management with new
*/

class Strategy {
public:
	int* order_qty;
	Strategy(int order_qty) : order_qty(new int (order_qty)) {
		cout << "Strategy class constructor called" << endl;
	}

	void fun() {
		cout << "This is Strategy class fun" << endl;
	}

	~Strategy() {
		cout << "Strategy class destructor called" << endl;
		delete order_qty;
	}
};

int main() {

	// Strategy obj(19);

	// obj.fun();

	Strategy* obj = new Strategy(100);
	obj->fun();
	//obj->~Strategy();
	delete obj;


	return 0;
}