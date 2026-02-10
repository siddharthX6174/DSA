#include<iostream>
using namespace std;

class Strategy {
public:
	double order_qty;
	Strategy() {
		order_qty = 10;
	}
	void fun() {
		cout << this << endl;
	}
};

int main() {
	Strategy s ;
	s.fun();

	return 0;
}