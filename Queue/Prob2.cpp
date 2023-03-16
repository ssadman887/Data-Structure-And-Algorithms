#include <iostream>
#include <string>

using namespace std;

class Queue {
public:
    int front, rear, size;
    unsigned cap;
    string* arr;

    Queue(unsigned cap) {
        this->cap = cap;
        this->front = this->size = 0;
        this->rear = cap - 1;
        this->arr = new string[cap];
    }

    ~Queue() {
        delete[] arr;
    }
};

int isFull(Queue* queue)
{
    return (queue->size == queue->cap);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, string item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
}

string dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return "Queue is empty.";
    string item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->cap;
    queue->size = queue->size - 1;
    return item;
}

string front(Queue* queue)
{
    if (isEmpty(queue))
        return "Queue is empty.";
    return queue->arr[queue->front];
}

string rear(Queue* queue)
{
    if (isEmpty(queue))
        return "Queue is empty.";
    return queue->arr[queue->rear];
}

// Function to reverse the order of strings in a queue
void reverseQueue(Queue* queue)
{
    if (isEmpty(queue))
        return;

    string* temp = new string[queue->cap];
    int i = 0;
    while (!isEmpty(queue)) {
        temp[i] = dequeue(queue);
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        enqueue(queue, temp[j]);
    }
    delete[] temp;
}

// Function to display contents of the queue
void displayQueue(Queue* queue)
{
    if (isEmpty(queue))
        return;

    for (int i = queue->front; i <= queue->rear; i++) {
        cout << queue->arr[i] << " ";
    }
    cout << endl;
}


// Driver code
int main()
{
    Queue* queue = new Queue(1000);
    enqueue(queue, "apple");
    enqueue(queue, "banana");
    enqueue(queue, "cherry");
    enqueue(queue, "is");
    enqueue(queue, "a");
    enqueue(queue, "queue");

    cout << "Queue before reversal: ";
    displayQueue(queue);
    cout << "Queue after reversal: ";
    reverseQueue(queue);
    displayQueue(queue);



}