#include<iostream>
using namespace std;

class Strategy {
private:
	int orderqty;
	int limit_price;
	int account_id;
	string account_name;

public:
	Strategy() {
		orderqty = -1;
		limit_price = -1;
		account_id = -1;
		account_name = "-1";
	}

	// setters
	void set_members(int orderqty, int limit_price, int account_id, string account_name) {
		this->orderqty = orderqty;
		this->limit_price = limit_price;
		this->account_id = account_id;
		this->account_name = account_name;
	}

	void Printfun() {
		cout << "orderqty : " << orderqty << "\n";
		cout << "limit_price : " << limit_price << "\n";
		cout << "account_id : " << account_id << "\n";
		cout << "account_name : " << account_name << "\n";
	}
};

int main() {
	Strategy* obj1 = new Strategy();

	(*obj1).set_members(4, 50, 342, "acc001");

	(*obj1).Printfun();

	delete obj1;
	return 0;
}