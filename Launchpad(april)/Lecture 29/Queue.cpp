#include<iostream>
#include"../Header_Files/Queue.h"
using namespace std;


int main() {

	Queue<int>s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.push(x);
	}

	while (!s.empty()) {
		cout << s.front1() << " ";
		s.pop();//Element is popped from front.
	}

}