#include <bits/stdc++.h>
using namespace std;

class Deque {
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Deque(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = capacity - 1;
        count = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    void addFront(int item) {
        if (isFull()) {
            std::cout << "Deque is full." << std::endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = item;
        count++;
    }

    void addRear(int item) {
        if (isFull()) {
            std::cout << "Deque is full." << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    void removeFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty." << std::endl;
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    void removeRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty." << std::endl;
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
        count--;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty." << std::endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty." << std::endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};



int main() {
    Deque  MyCircularDeque(5); 

    MyCircularDeque.addFront(3);
    MyCircularDeque.addRear(4);
    MyCircularDeque.addRear(5);
    MyCircularDeque.removeRear();
    MyCircularDeque.addFront(2);
    MyCircularDeque.removeFront();
    cout<< "Is the Deque empty?\n"<< (MyCircularDeque.isEmpty()? "True": "False")<<endl;


    
}


