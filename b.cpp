#include <iostream>
#include<vector>
using namespace std;

class node {
public:
    int val;
    node* prev;
    node() {
        val = 0;
        prev = NULL;
    }
};

class stack {
public:
    node* end;
    int i; // current index in popped array

    stack() {
        end = NULL;
        i = 0;
    }
    void print();
    void pop();
    void push(int a, const vector<int>& popped);
    int peek(void);
};

// adds to end of stack
void stack::push(int a, const vector<int>& popped) {
    node* temp = new node();
    temp->val = a;
    temp->prev = end;
    end = temp;

    // check if top element of stack matches current element in popped array
    while (end && end->val == popped[i]) {
        pop();
        i++;
    }
}

// returns last element of stack
int stack::peek(void) {
    return end->val;
}

// removes last element of stack
void stack::pop(void) {
    if (end == NULL) {
        return;
    }
    node* temp = end;
    end = end->prev;
    free(temp);
}

// prints the stack back to front
void stack::print(void) {
    node* temp = end;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack mystack;
    for (int x : pushed) {
        mystack.push(x, popped);
    }
    return mystack.i == popped.size();
}

int main(void) {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    bool result = validateStackSequences(pushed, popped);
    cout << boolalpha << result << endl;
    return 0;
}

/*Initialize an empty stack and a pointer i to 0.
Iterate over each element in the pushed array:
a. Push the current element onto the stack.
b. While the stack is not empty and the top element of the stack is equal to the current element in the popped array:
i. Pop the top element from the stack.
ii. Increment the pointer i.
If the stack is empty and the pointer i is equal to the length of the popped array, return true. Otherwise, return false.*/