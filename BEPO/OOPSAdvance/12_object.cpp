#include<iostream>
using namespace std;

class A {
//private:
public:
	int num;

//public:
	A(int num) {
		this->num = num;
	}

	void printdetail() {
		cout << " number : " << num << "\n";
	}
};

int main() {
	A obj(10);
	// obj.printdetail();
	cout << obj.num << endl;
	cout << &obj << endl;

	return 0;
}