# include <iostream>

class node {
public:
	int data;
	node* next;

	// self constructor
	node() {
	}

	//constructor
	node(int inputdata) {
		data = inputdata;
		next = nullptr;
	}
};

int main() {
	node x(10);

	std::cout << x.data << std::endl;
	std::cout << x.next << std::endl;
}