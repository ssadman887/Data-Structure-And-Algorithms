#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
public:
    Node* head;

    Stack() {
        head = nullptr;
    }

    void push(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    int pop() {
        if (head == nullptr) {
            return -1; // return -1 to indicate underflow
        }
        Node* popped_node = head;
        head = head->next;
        popped_node->next = nullptr;
        int data = popped_node->data;
        delete popped_node;
        return data;
    }

    int peek() {
        if (head == nullptr) {
            return -1; // return -1 to indicate underflow
        }
        return head->data;
    }

    bool is_empty() {
        return head == nullptr;
    }

    void display() {
        Node* current_node = head;
        while (current_node != nullptr) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // expected output: 30 20 10
    cout << s.pop() << endl; // expected output: 30
    cout << s.peek() << endl; // expected output: 20
    cout << s.pop() << endl; // expected output: 20
    s.display(); // expected output: 10
    return 0;
}
