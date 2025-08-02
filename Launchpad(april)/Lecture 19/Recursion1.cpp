#include<iostream>
using namespace std;


/*
	OP: We want to build the building till the nth floor.

	BP: We want to build the building from 1st to nth floor.
	SP: We want to build the building from 2nd to nth floor.

	Changing Parameter: One that represents from which building we
	are trying to build till nth floor.

	F(1): We want to build the building from 1st to nth floor.
	F(2): We want to build the building from 2nd to nth floor.


	F(x): We want to build the building from xth to nth floor.

	Recursive Relation:
	F(1): Build FLoor 1st + F(2);
	F(x): Build Floor x + F(x+1);

	Base Case:
	F(n): We are trying to build the floor from nth to nth.

	Recursion is a Technique with fundamentals similar
	to loops:

	Starting Point
	Ending Point
	Task
	Next State par kaise jaaye.
*/

int n;

void F(int x) {

	/*
		We are trying to find the answer for state F(x)
		and since x==1 for the first case :
		We can also say we are trying to find the answer
		for the state F(1).
	*/

	//Stoping Point: Base Case:
	if (x == n) {
		//THis will mean we are trying to find the
		// answer for the state F(n) which the last
		// state and hence we know its answer.

		//I will return to give the answer for the current state.
		//Return main usko karunga jisne mujhe call kiya hain.


		return (Build the nth floor);

	}

	//Task:
	Build Floor x.

	//Move to the next state:
	F(x + 1);




}



int main() {

	int n;
	cin >> n;


	F(1); //THis is the original problem or the starting point.







}