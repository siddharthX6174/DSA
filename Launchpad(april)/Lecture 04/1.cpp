# include <iostream>

int main() {
	// Defining a variable
	int a;


	//Define and initialise
	int b = 25;

	//Types of initializatin in c++.
	int c = 78; //copy assignment (Expensive Operatin)

	//General Initialisation
	int d = {89}; // copy list inintialisation

	// general
	int e {80}; // Direct List initialisation

	//Narrowing of data
	int f = 89.7;
	std::cout << f << std::endl;


	// narrowing of data is not allowed in direct list initialisation
	int h{79.9};

}