#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* prev;

    Node(int v) {
        val = v;
        prev = nullptr;
    }
};

class Stack {
private:
    Node* end;

public:
    Stack() {
        end = nullptr;
    }

    void push(int a) {
        Node* temp = new Node(a);
        temp->prev = end;
        end = temp;
    }

    int pop() {
        if (end == nullptr) {
            return -1; // stack underflow error
        }
        Node* temp = end;
        end = end->prev;
        int val = temp->val;
        delete temp;
        return val;
    }

    int peek() {
        if (end == nullptr) {
            return -1; // stack underflow error
        }
        return end->val;
    }

    bool empty() {
        return end == nullptr;
    }

    int evalRPN(vector<string>& tokens) {
        for (string token : tokens) {
            if (token == "+") {
                int b = pop();
                int a = pop();
                push(a + b);
            } else if (token == "-") {
                int b = pop();
                int a = pop();
                push(a - b);
            } else if (token == "*") {
                int b = pop();
                int a = pop();
                push(a * b);
            } else if (token == "/") {
                int b = pop();
                int a = pop();
                push(a / b);
            } else {
                push(stoi(token));
            }
        }
        return pop();
    }
};

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Stack s;
    cout << s.evalRPN(tokens) << endl; // output: 9

    tokens = {"4", "13", "5", "/", "+"};
    cout << s.evalRPN(tokens) << endl; // output: 6

    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << s.evalRPN(tokens) << endl; // output: 22

    return 0;
}
