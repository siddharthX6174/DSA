# include <iostream>
using namespace std;


template<typename T>
class Vector {
private:
	T* a;
	int ts;
	int cs;

public:
	// Constructor
	// Vector() {
	// 	// Default constructor
	// }

	Vector() {
		cs = 0;
		ts = 1;
		a = new T[ts];
	}



	// parameterised contructor
	Vector (int n) {
		cs = 0; // this can be treated as index also
		ts = 1;
		a = new T[n];
	}



	// Member Functions:
	void push_back(T data) {

		if (cs == ts) {
			T* b = a;
			a = new T[2 * ts];
			ts = ts * 2;

			// copy the contnet of the old array in new array.
			for (int i = 0; i < ts / 2; i++) {
				a[i] = b[i];
			}

			delete[] b; // To avoid memory leak.
		}
		a[cs] = data;
		cs++;

	}

	int size() {
		return cs;
	}

	int capactiy() {
		return ts;
	}

	void pop_back() {
		cs--;
	}

	void front() {
		return a[0];
	}

	void back() {
		return a[cs - 1];
	}

	bool empty() {
		if (cs == 0) {
			return true;
		} else {
			return false;
		}
	}

	// v[5] : *(v + 5)
	//v.operator[](5)

	T operator[] (int index) {
		return a[index];
	}

};



// template <typename T1, typename T2>

// class Mayank {

// };