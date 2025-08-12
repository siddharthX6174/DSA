#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class stack {
public:
    node* top;
    int size;

    stack() {
        top = nullptr;
        size = 0;
    }

    void push(int value) {
        node* temp = new node(value);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    bool is_empty() {
        return (top == nullptr);
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    int size_stack() {
        return size;
    }

    void display() {
        node* temp = top;
        if (temp == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    s.pop();

    cout << "Is empty: " << s.is_empty() << endl;
    cout << "Top element: " << s.peek() << endl;
    cout << "Size: " << s.size_stack() << endl;

    s.display();

    return 0;
}
