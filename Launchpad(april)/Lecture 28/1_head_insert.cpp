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


// find the mid point one
int MidPoint1(node* head) {
	int mid = Length(head) / 2;
	while (mid) {
		head = head->next;
		mid--;
	}
	return head->data;
}

// Second mid point in case of even lenght linked list
int MidPoint2(node * head) {
	node * slow = head;  // x speed
	node * fast = head;  // 2x speed

	while ((fast != nullptr) and (fast->next != nullptr)) {

		slow = slow->next;
		fast = fast->next->next;
	}

	// you have found the mid point2 and currently slow pointer is pointing it to it

	return slow->data;
}

// new optimixes logic for the first mid point in even and odd lenght
node* MidPoint3 (node* head) {
	node* slow = head;
	node* fast = head->next;

	while ((fast != nullptr) and (fast->next != nullptr)) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}


// seraching the element in iterative way
// bool SearchIterative (node* head, key) {
// 	while (head != nullptr) {
// 		if (head->data == key) return true;
// 		head = head->next;
// 	}
// 	return false;
// }

// // searching recursive way
// bool SearchRecursive (node* head, key) {
// 	// base
// 	if (head == nullptr) {
// 		return false;
// 	}

// 	// task
// 	if (head->data == key) {
// 		return true;
// 	}

// 	bool ans = SearchRecursive(head->next, key);

// 	return ans;
// }

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

	print(head);
	// std::cout << "length of linked list : " << Length(head) << std::endl;
	// std::cout << "midPoint1 : " << MidPoint1(head) << std::endl;
	// std::cout << "MidPoint2 : " << MidPoint2(head) << std::endl;

	// std::cout << "MidPoint3 : " << MidPoint3(head)->data << std::endl;


}