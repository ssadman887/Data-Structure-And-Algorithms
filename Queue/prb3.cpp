#include <bits/stdc++.h>
using namespace std;

// function to find the smallest subsequence of consecutive elements in a queue that add up to at least x

int* find_subsequence(int* queue, int queue_size, int x, int* subseq_size) {
    // initialize variables
    int current_sum = 0;
    int start_index = 0;
    int end_index = -1;
    int min_length = queue_size + 1;

    // loop through the queue
    for (int i = 0; i < queue_size; i++) {
        current_sum += queue[i];

        // check if the sum is greater than or equal to x
        while (current_sum >= x) {
            // update the minimum length and indices
            if (i - start_index + 1 < min_length) {
                min_length = i - start_index + 1;
                end_index = i;
            }

            // subtract the first element in the subsequence
            current_sum -= queue[start_index];
            start_index++;
        }
    }

    // check if a subsequence was found
    if (end_index == -1) {
        *subseq_size = 0;
        return NULL;
    }

    // create the subsequence array
    *subseq_size = min_length;
    int* subseq = new int[min_length];
    for (int i = 0; i < min_length; i++) {
        subseq[i] = queue[start_index + i];
    }

    return subseq;
}


class Queue {
public:
    int front, rear, size;
    unsigned cap;
    int* arr;

    // constructor to create a queue of given capacity
    Queue(unsigned cap) {
        this->cap = cap;
        front = size = 0;
        rear = cap - 1;
        arr = new int[(cap * sizeof(int))];
    }

    // function to check if the queue is full
    bool isFull() {
        return (size == cap);
    }

    // function to check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }

    // function to add an item to the rear of the queue
    void enqueue(int item) {
        if (isFull())
            return;
        rear = (rear + 1) % cap;
        arr[rear] = item;
        size++;
        cout << item << " enqueued to queue\n";
    }

    // function to remove an item from the front of the queue
    int dequeue() {
        if (isEmpty())
            throw runtime_error("Queue is empty");
        int item = arr[front];
        front = (front + 1) % cap;
        size--;
        return item;
    }

    // function to get the front item of the queue without removing it
    int getFront() {
        if (isEmpty())
            throw runtime_error("Queue is empty");
        return arr[front];
    }

    // function to get the rear item of the queue without removing it
    int getRear() {
        if (isEmpty())
            throw runtime_error("Queue is empty");
        return arr[rear];
    }

    // function to find the smallest subsequence of consecutive elements in the queue that add up to at least x
    int* findSmallestSubsequence(int x, int* subseq_size) {
        // convert the queue to an array
        int* queue_arr = new int[size];
        int index = 0;
        for (int i = front; i <= rear; i++) {
            queue_arr[index] = arr[i];
            index++;
        }

        // find the smallest subsequence
        int* subseq = find_subsequence(queue_arr, size, x, subseq_size);

        // free memory
        delete[] queue_arr;

        return subseq;
    }
};

// Driver code
int main()
{
	Queue q(1000);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);


    int subseq_size;
    int* subseq = q.findSmallestSubsequence(7, &subseq_size);

    if (subseq == NULL) {
        cout << "No subsequence found\n";
    } else {
        cout << "Smallest subsequence found: ";
        for (int i = 0; i < subseq_size; i++) {
            cout << subseq[i] << " ";
        }
        cout << endl;
        delete[] subseq;
    }

    return 0;
}
