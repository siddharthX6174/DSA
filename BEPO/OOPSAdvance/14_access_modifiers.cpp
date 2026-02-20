#include<iostream>
using namespace std;

class ParentStrategy {
public:
	double order_qty;
	double price;

	ParentStrategy(double qty, double prc) : order_qty(qty), price(prc) {};

	void PrintStrategy() {
		cout << "order_qty:\t" << order_qty << endl;
		cout << "price:\t" << price << endl;
	}

	void SubmitStrategy() {
		cout << "Submitting the order to the exchange" << endl;
	}

protected:
	void ModifyStrategy() {
		cout << "Modifying the strategy" << endl;
	}

private:
	void CancelStrategy() {
		cout << "Cancel the strategy" << endl;
	}
};

class Strategy : public ParentStrategy {
public:
	// calling parent strategy class ka constructor...
	Strategy(double qty, double prc) : ParentStrategy(qty, prc) {};

	void CreateStrategy() {
		cout << "Strategy creation is doing" << endl;
		SubmitStrategy();
		ModifyStrategy();
		//CancelStrategy();
	}
};


int main() {
	Strategy s(100, 100);
	s.PrintStrategy();
	//s.SubmitStrategy();
	//s.ModifyStrategy();

	s.CreateStrategy();

	return 0;
}