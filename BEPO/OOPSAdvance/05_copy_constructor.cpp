#include<bits/stdc++.h>
using namespace std;

class Strategy {
private:
	int price;
	int orderqty;
	string account_name;
public:

	Strategy() = delete;

	Strategy(int price, int orderqty, string account_name) {
		cout << "Parameterised Constructor  invoked \n";
		this->price = price * 1000;  // complex operaitons inside constructor initialsiation
		this->orderqty = orderqty;
		this->account_name = account_name;
	}

	Strategy(int price) {
		this->price = price;
	}

	void Printfun() {
		cout << "object Price : " << price << endl;
		cout << "object orderqty : " << orderqty << endl;
		cout << "object account_name : " << account_name << endl;
	}

	// copy constructor , parameterised constructor
	Strategy(const Strategy& obj) {
		cout << "copy Constructor invoked\n";
		price = obj.price;
		orderqty = obj.orderqty;
		account_name = obj.account_name;
	}

};

int main() {
	Strategy obj(100, 10, "karan");
	//obj.Printfun();

	Strategy obj2(obj);
	obj2.Printfun();

	return 0;
}