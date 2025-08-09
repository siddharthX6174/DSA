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


// length of sinlgy linked list
int Length(node* head) {
	int l{};
	while (head != nullptr) {
		l++;
		head = head->next;
	}
	return l;
}


// cycle creation
void CycleCreation(node* &head) {
	node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = head->next->next->next;
}


// detect the cycle
bool is_cycle(node* head) {
	node* slow = head;
	node* fast = head;

	while (fast != nullptr and fast->next != nullptr) {
		slow = slow->next;  // x
		fast = fast->next->next; //2x

		if (slow == fast) {
			return true;
		}
	}

	return false;
}


// delete cycle
void break_cycle(node* head) {
	node*fast = head;
	node*slow = head;

	while (fast->next != nullptr and fast != nullptr) {
		fast = fast->next;
		slow = slow->next;

		if (slow == fast) {
			break;
		}
	}

	// Now fast and slow pointer both are at standing at the meeting point
	slow = head;

	node*prev = head;
	while (prev->next != fast) {
		prev = prev->next;
	}

	// now my fast is at meeting point , slow is at head, prev is just before fast
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
		prev = prev->next;
	}

	// Now my prev is at the last node and fast/slow is at the origin of cycle
	prev->next = nullptr;  // now my cycle is breakdown
}

int main() {
	node* head = nullptr;

	// int n{};
	// std::cin >> n;
	// for (int i=0; i<n; i++){
	// 	int x{};
	// 	std::cin >> x;
	// 	InsertAtHead(head, x);
	// }

	int x{};
	while (std::cin >> x) {
		InsertAtHead(head, x);
	}

	std::cout << is_cycle(head) << std::endl;
	CycleCreation(head);
	std::cout << is_cycle(head) << std::endl;

}