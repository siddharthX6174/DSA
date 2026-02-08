#include<bits/stdc++.h>
using namespace std;

class Strategy {
private:
	int price;
	int orderqty;
	string account_name;
public:
	// i am restricting the deafult constructor
	Strategy() = delete;
	// default contructor inovked
	// Strategy() {
	// 	cout << "Default Constructor invoked \n";
	// 	price = 0;
	// 	orderqty = 0;
	// 	account_name = "NULL";
	// }
	// Parameterised constructor
	Strategy(int price, int orderqty, string account_name) {
		cout << "Parameterised Constructor  invoked \n";
		this->price = price;
		this->orderqty = orderqty;
		this->account_name = account_name;
	}
	// Parameterised constructor
	Strategy(int price) {
		this->price = price;
	}

	void Printfun() {
		cout << "object Price : " << price << endl;
		cout << "object orderqty : " << orderqty << endl;
		cout << "object account_name : " << account_name << endl;
	}

};

int main() {
	Strategy obj(100, 10, "karan");
	obj.Printfun();

	// Strategy obj2;  // will give error now due to restriction in the deault constructor
	// obj2.Printfun();

	return 0;
}