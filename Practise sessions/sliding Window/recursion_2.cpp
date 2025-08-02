#include<iostream>
using namespace std;


/*
	Q. Calculate n^p.

	BP: Multiply n from (1 to p) times.
	SP: Multiply n from (3 to p) times.

	CHanging Parameters:  One : From where till
	end count we need to multiply n.

	F(1): Multiply n from 1 to p times.
	F(1): It gives me value while multiplying n 1 to p times.
	F(x): Multiply n from x to p times.

	Recursive Relation:

	F(1): n * F(2);
	F(x): n * F(x+1);

	Base Condtion:

	F(p): n ; I want to multiply n from p to p times.
	i.e I want to multiply n 1 time.
	i.e. F(p) = n;

	F(p+1): 1;

	Multiply n from p+1 to p times
	which is not possible so we say i will return
	a value that when multiplied will never
	impact my answer.


*/
int n, p;

int F(int x) {

	// if (x == p) {
	// 	return n;
	// }


	if (x == p + 1) {
		return 1;
	}

	int task = n * F(x + 1);
	return task;
}



int main() {


	cin >> n >> p;

	int ans = 1;

	for (int i = 0; i < p; i++) {
		ans *= n;
	}

	cout << ans << endl;


	int value = F(1); //Starting Point
	cout << value << endl;

}