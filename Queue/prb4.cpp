// Implementation of queue(enqueue, dequeue).
#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
	int front, rear, size;
	unsigned cap;
	int* arr;
};

Queue* createQueue(unsigned cap)
{
	Queue* queue = new Queue();
	queue->cap = cap;
	queue->front = queue->size = 0;

	queue->rear = cap - 1;
	queue->arr = new int[(queue->cap * sizeof(int))];
	return queue;
}

int isFull(Queue* queue)
{
	return (queue->size == queue->cap);
}

int isempty(Queue* queue) { return (queue->size == 0); }
// Function to add an item to the queue.
// It changes rear and size.
void enqueue(Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->cap;
	queue->arr[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << item << " enqueued to queue\n";
}
// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue* queue)
{
	if (isempty(queue))
		return INT_MIN;
	int item = queue->arr[queue->front];
	queue->front = (queue->front + 1) % queue->cap;
	queue->size = queue->size - 1;
	return item;
}
int front(Queue* queue)
{
	if (isempty(queue))
		return INT_MIN;
	return queue->arr[queue->front];
}
int rear(Queue* queue)
{
	if (isempty(queue))
		return INT_MIN;
	return queue->arr[queue->rear];
}

int sumOfKthElements(Queue* queue, int K) {
    int sum = 0;
    int count = 0;
    int i = queue->front;

    while (count < queue->size) {
        if (count % K == 0) {
            sum += queue->arr[i];
        }

        i = (i + 1) % queue->cap;
        count++;
    }

    return sum;
}

void testSumOfKthElements() {
    Queue* queue = createQueue(1000);

    // Enqueue some elements to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);

    // Test sum of every 2nd element
    int K = 2;
    int sum = sumOfKthElements(queue, K);
    cout << "Sum of every " << K << "th element is " << sum << endl;

    // Test sum of every 3rd element
    K = 3;
    sum = sumOfKthElements(queue, K);
    cout << "Sum of every " << K << "rd element is " << sum << endl;

    // Test sum of every 4th element
    K = 4;
    sum = sumOfKthElements(queue, K);
    cout << "Sum of every " << K << "th element is " << sum << endl;

    // Dequeue all elements from the queue
    while (!isempty(queue)) {
        dequeue(queue);
    }

    // Test sum on an empty queue
    K = 2;
    sum = sumOfKthElements(queue, K);
    cout << "Sum of every " << K << "th element on an empty queue is " << sum << endl;

    // Free the memory allocated for the queue
    delete[] queue->arr;
    delete queue;
}

int main() {
    testSumOfKthElements();
    return 0;
}


