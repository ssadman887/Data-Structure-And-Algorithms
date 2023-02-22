#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
public:
    int arr[MAX_SIZE];
    int top;

    Stack() {
        top = -1;
    }

    void push(int data) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int data = arr[top];
        top--;
        return data;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool is_empty() {
        return top == -1;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
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
