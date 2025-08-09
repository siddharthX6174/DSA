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


// insertion in sinlgy linked list
void InsertAtHead(node* &head, int x) {
	if (head == nullptr) {
		node* temp = new node(x);
		head = temp;
	} else {
		node* temp = new node(x);
		temp->next = head;
		head = temp;
	}
}


// printing the linked list
void print(node* &head) {
	node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << " ---> " ;
		temp = temp->next;
	}
	std::cout << "NULL" <<  std::endl;
}


//reverse the singly linked list
void ReverseIterative (node* &head) {
	node* current = head;
	node* prev = nullptr;
	node* n = nullptr;

	while (current != nullptr) {
		n = current->next;
		current->next = prev;
		// sabko aage badhao
		prev = current;
		current = n;
	}

	// current is at null hence prev is at last node.
	head = prev;
}

// recursivvvely reverse
node* ReverseRecursive (node* head) {
	// base case:
	if (head == nullptr or head->next == nullptr) {
		return head;
	}

	node* new_head = ReverseRecursive(head->next);

	node*current = head;
	current->next->next = current;
	current->next = nullptr;

	return new_head;
}


int main() {
	node* head = nullptr;

	int x{};
	while (std::cin >> x) {
		InsertAtHead(head, x);
	}

	print(head);

	ReverseIterative(head);
	print(head);

	node* head2 = ReverseRecursive(head);
	print(head2);


	return 0;
}