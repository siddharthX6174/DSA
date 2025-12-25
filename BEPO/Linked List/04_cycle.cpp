#include<iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;

	ListNode() {
		next = nullptr;
	}

	ListNode(int x) {
		val = x;
		next = nullptr;
	}
};

void InsertAtHead(ListNode* &head, int x) {
	if (head == nullptr) {
		ListNode* temp = new ListNode (x);
		head = temp;
	} else {
		ListNode* temp = new ListNode (x);
		temp->next = head;
		head = temp;
	}
}

void Print(ListNode* &head) {
	ListNode* temp = head;
	while (temp) {
		cout << temp->val << " --> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

void cycleCreation(ListNode* &head) {
	ListNode* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = head->next->next;
}

// detection of cycle :->  2 person running with differnt sppeeds in a circular loop meet at a point
bool isCycle(ListNode* &head) {
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != nullptr and fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) return true;
	}

	return false;
}


void breakCycle(ListNode* &head) {
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != nullptr and fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) break;
	}

	// Now slow and fast are at meeting point inside the loop somewhere.. make prev at fast se just before.. and slow at head
	slow = head;

	ListNode* prev = head;
	while (prev->next != fast) {
		prev = prev->next;
	}

	/*
		now ->
			fast -> meeting point
			slow -> head
			prev -> just before fast

		now move 1 step slow and fast upto they meet
	*/

	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
		prev = prev->next;
	}

	// prev is just before the loop creating starting point make prev-> next as null now..
	prev->next = nullptr; // cycle is now break...


}


int main() {
	ListNode* head = nullptr;
	int a{};
	while (cin >> a) {
		InsertAtHead(head, a);
	}


	cycleCreation(head);
	cout << isCycle(head);

}