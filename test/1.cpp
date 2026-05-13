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

void reverseList(ListNode* &head) {
	ListNode* prev = nullptr;
	ListNode* current = head;
	ListNode* temp = head;

	while (current != nullptr) {
		temp = current->next;
		current -> next = prev;

		prev = current;
		current = temp;
	}

	head = prev;
}

bool helper(node* current, int a) {
	if (current->next != nullptr) {
		node* temp = current;
		while (temp != nullptr) {
			if (temp->val > a) {

				return true;
				break;
			}
			temp = temp->next;
		}
	}
	return false;
}

void rem(node* &current) {

}

void fun(node* &head) {
	node* current = head;
	while (current != nullptr) {
		int element = a->val;
		bool a = helper(current, a);
		if (a) {
			current = current->next;
		} else {
			// remove this node
			rem(current);
		}
	}
}

int main() {
	ListNode* head = nullptr;
	int a{};
	while (cin >> a) {
		InsertAtHead(head, a);
	}

	// Print(head);

	// cout << "reversing it \n";

	reverseList(head);

	Print(head);

}

/*

	given a sinlgy linked list of integers. repeatedly remove all nodes that do not have a next greater element to their right.

	a node has a next greater element if there exits some norde after it with a value strictly greater than its vale. if no suc nodeexists the node is removed . repeat this process untill no more nodes can be removes..
*/