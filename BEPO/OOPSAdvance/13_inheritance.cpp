#include<iostream>
using namespace std;

class Base {
public:
	void function() {
		cout << "printing using base class function\n";
	}
};

class Derived : public Base {
public:
	int x = 10;
	void function1() {
		cout << "Output from derived class\n";
		cout << "value of x : " << x << endl;
	}
};



int main() {
	Derived d;
	d.function();
	d.function1();

	Base b;
	b.function();
	//b.function1();
	return 0;
}