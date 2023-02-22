#include <bits/stdc++.h>
using namespace std;


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;


void push(int item) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = top;
    top = new_node;
}


int pop() {
    if (top == NULL) {
        printf("jinis nai ar bhai!!\n");
        return -1;
    }
    int item = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return item;
}

int peek() {
    if (top == NULL) {
        printf("steak khali, just like my brain\n");
        return -1;
    }
    return top->data;
}

int main() {
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop()); 
    printf("%d\n", peek()); 
    push(4);
    printf("%d\n", pop()); 
    printf("%d\n", pop()); 
    printf("%d\n", pop()); 
    printf("%d\n", pop()); 
    return 0;
}

