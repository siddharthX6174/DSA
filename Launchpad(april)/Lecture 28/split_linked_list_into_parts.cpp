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
