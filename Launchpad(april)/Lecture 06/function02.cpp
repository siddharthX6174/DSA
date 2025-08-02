# include <iostream>



// Function overloading ---

/*int sum1(int x, int y){
	return x + y;
}

int sum2(int x, int y, int z){
	return x + y + z;
}

int sum3(int x, int y, int z, int t){
	return x + y + z + t;
}

double sum4 (int x, double y, double z){
	return x + y + z;
}
*/

// overloading below---
/*
int sum(int x, int y){
	return x + y;
}

int sum(int x, int y, int z){
	return x + y + z;
}

int sum(int x, int y, int z, int t){
	return x + y + z + t;
}

double sum(int x, double y, double z){
	return x + y + z;
}*/


// default --
double sum(double x = 0.0, double y = 0.0, double z = 0.0, double t = 0.0) {
	return x + y + z + t;
}


// template