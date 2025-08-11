#include<iostream>
using namespace std;
#define MAX 1000

template<typename T>
class Queue {
public:
	T *a;
	int front;
	int back;

	int cs;//Current size kya hain.
	int ts;

	Queue() {
		front = back = - 1;
		a = new T[MAX];
		cs = 0;
		ts = MAX;
	}

	Queue(int size) {
		front = back = - 1;
		a = new T[size];
		cs = 0;
		ts = size;
	}

	void push(int x) {

		if (cs == ts) {
			return;
		}

		if (cs == 0) {
			//Queue is empty
			front = 0;
		}

		back = (back + 1) % ts;
		a[back] = x;
		cs++;
	}

	void pop() {

		if (cs == 0) {
			return;
		}

		if (cs == 1) {
			back = front = -1;
		} else {
			//Remove from front.
			front = (front + 1) % ts;
		}

		cs--;
	}

	bool empty() {
		if (cs == 0) {
			return 1;
		} else {
			return 0;
		}
	}


	T front1() {
		if (cs == 0) {
			return -1;
		} else {
			return a[front];
		}
	}

};


