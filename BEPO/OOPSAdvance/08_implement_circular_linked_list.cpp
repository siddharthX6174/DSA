#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node() : data(0), next(nullptr) {};
	node(int val) : data(val), next(nullptr) {};
};

class circularlist {
private:
	node* head;
public:
	circularlist(): head(nullptr) {};
	//----------------------------------------------------------
	// deep copy constructor
	circularlist(const circularlist& lst) : head(nullptr) {
		if (lst.head == nullptr) {
			return;
		}
		// copy first node
		head = new node(lst.head->data);
		node* currNew = head;
		node* currOld = lst.head->next;
		// copy remaining nodes
		while (currOld != lst.head) {
			currNew->next = new node(currOld->data);
			currNew = currNew->next;
			currOld = currOld->next;
		}
		currNew->next = head;
	}


	// copy assignmanet operartor=
	circularlist& operator=(const circularlist& other) {
		// 1️⃣ Self-assignment check
		if (this == &other)
			return *this;
		// 2️⃣ Delete existing list
		this->~circularlist();
		// 3️⃣ If other list is empty
		if (other.head == nullptr) {
			head = nullptr;
			return *this;
		}
		// 4️⃣ Deep copy (same logic as copy constructor)
		head = new node(other.head->data);
		node* currNew = head;
		node* currOld = other.head->next;
		while (currOld != other.head) {
			currNew->next = new node(currOld->data);
			currNew = currNew->next;
			currOld = currOld->next;
		}
		currNew->next = head;  // make circular
		return *this;
	}






	//---------------------------------------------------------

	void insert(int val) {
		node* newnode = new node(val);

		if (head == nullptr) {
			head = newnode;
			newnode->next = head;
			return;
		}

		node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}

		temp->next = newnode;
		newnode->next = head;
	}

	void display() {
		if (head == nullptr) {
			cout << "List is empty() : \n";
			return ;
		}

		node* temp = head;

		do {
			cout << temp->data << " --> ";
			temp = temp->next;
		}
		while (temp != head);

		cout << "(back to head again):" << temp->data << " \n";

	}


	// destructor
	~circularlist() {
		if (head == nullptr)
			return;

		node* curr = head->next;
		while (curr != head) {
			node* temp = curr;
			curr = curr->next;
			delete temp;
		}
		delete head;
		head = nullptr;
	}

};

int main() {
	circularlist lst;

	int x ;
	while (cin >> x) {
		lst.insert(x);
	}

	lst.display();


	circularlist b = lst;

	b.display();

	return 0;
};