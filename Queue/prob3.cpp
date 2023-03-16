/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

class Queue {
public:
    int front, rear, size;
    unsigned cap;
    int* arr;

    Queue(unsigned cap) {
        this->cap = cap;
        this->front = this->size = 0;
        this->rear = cap - 1;
        this->arr = new int[cap];
    }

    bool isFull() {
        return (this->size == this->cap);
    }

    bool isEmpty() {
        return (this->size == 0);
    }

    void enqueue(int item) {
        if (isFull())
            return;
        this->rear = (this->rear + 1) % this->cap;
        this->arr[this->rear] = item;
        this->size = this->size + 1;
    }

    int dequeue() {
        if (isEmpty())
            return INT_MIN;
        int item = this->arr[this->front];
        this->front = (this->front + 1) % this->cap;
        this->size = this->size - 1;
        return item;
    }

    int getFront() {
        if (isEmpty())
            return INT_MIN;
        return this->arr[this->front];
    }

    int getRear() {
        if (isEmpty())
            return INT_MIN;
        return this->arr[this->rear];
    }
};

void find_subsequence(Queue* queue, int x, int* out_result, int* out_n) {
    int n = queue->size;
    int min_length = n + 1;
    int start = 0;
    int end = 0;
    int current_sum = 0;

    while (end < n) {
        // If adding the next element puts us over x, try to shrink the subsequence
        while (current_sum + queue->arr[(queue->front + end) % queue->cap] > x && start <= end) {
            current_sum -= queue->dequeue();
            start += 1;
        }
        
        // If the current subsequence satisfies the condition, update the result if it's smaller than any previous subsequence
        if (current_sum >= x) {
            int length = end - start + 1;
            if (length < min_length || (length == min_length && (out_result == NULL || start < out_result[0]))) {
                min_length = length;
                for (int i = 0; i < length; i++) {
                    out_result[i] = queue->arr[(queue->front + start + i) % queue->cap];
                }
            }
        }
        
        // Add the next element to the subsequence
        if (end < n) {
            current_sum += queue->arr[(queue->front + end) % queue->cap];
            end += 1;
        }
    }
    
    // Return the smallest subsequence that satisfies the condition
    *out_n = min_length;
}

/*int* find_subsequence(Queue* queue, int x, int* out_n) {
    int n = queue->size;
    int min_length = n + 1;
    int* result = NULL;
    int start = 0;
    int end = 0;
    int current_sum = 0;

    while (end < n) {
        // If adding the next element puts us over x, try to shrink the subsequence
        while (current_sum + queue->arr[(queue->front + end) % queue->cap] > x && start <= end) {
            current_sum -= queue->dequeue();
            start += 1;
        }
        
        // If the current subsequence satisfies the condition, update the result if it's smaller than any previous subsequence
        if (current_sum >= x) {
            int length = end - start + 1;
            if (length < min_length || (length == min_length && (result == NULL || start < result[0]))) {
                min_length = length;
                free(result);
                result = malloc(sizeof(int) * length);
                for (int i = 0; i < length; i++) {
                    result[i] = queue->arr[(queue->front + start + i) % queue->cap];
                }
            }
        }
        
        // Add the next element to the subsequence
        if (end < n) {
            current_sum += queue->arr[(queue->front + end) % queue->cap];
            end += 1;
        }
    }
    
    // Return the smallest subsequence that satisfies the condition
    *out_n = min_length;
    return result;
}


int main() {
    Queue queue(1000);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);

    int x = 17;
    int result[1000];
    int out_n;

    find_subsequence(&queue, x, result, &out_n);

    printf("[");
    for (int i = 0; i < out_n; i++) {
        printf("%d", result[i]);
        if (i < out_n-1) {
            printf(", ");
        }
    }
    printf("]\n");  // Output: [2, 3, 4, 5, 6]

    return 0;
}*/

#include <iostream>
#include <climits>

class Queue {
public:
    int front, rear, size;
    unsigned cap;
    int* arr;

    Queue(unsigned cap) {
        this->cap = cap;
        this->front = this->size = 0;
        this->rear = cap - 1;
        this->arr = new int[cap];
    }

    bool isFull() {
        return (this->size == this->cap);
    }

    bool isEmpty() {
        return (this->size == 0);
    }

    void enqueue(int item) {
        if (isFull())
            return;
        this->rear = (this->rear + 1) % this->cap;
        this->arr[this->rear] = item;
        this->size = this->size + 1;
    }

    int dequeue() {
        if (isEmpty())
            return INT_MIN;
        int item = this->arr[this->front];
        this->front = (this->front + 1) % this->cap;
        this->size = this->size - 1;
        return item;
    }

    int getFront() {
        if (isEmpty())
            return INT_MIN;
        return this->arr[this->front];
    }

    int getRear() {
        if (isEmpty())
            return INT_MIN;
        return this->arr[this->rear];
    }
};

void find_subsequence(Queue* queue, int x, int* out_result, int* out_n) {
    int n = queue->size;
    int min_length = n + 1;
    int start = 0;
    int end = 0;
    int current_sum = 0;

    while (end < n) {
        // If adding the next element puts us over x, try to shrink the subsequence
        while (current_sum + queue->arr[(queue->front + end) % queue->cap] > x && start <= end) {
            current_sum -= queue->dequeue();
            start += 1;
        }
        
        // If the current subsequence satisfies the condition, update the result if it's smaller than any previous subsequence
        if (current_sum >= x) {
            int length = end - start + 1;
            if (length < min_length || (length == min_length && (out_result == nullptr || start < out_result[0]))) {
                min_length = length;
                for (int i = 0; i < length; i++) {
                    out_result[i] = queue->arr[(queue->front + start + i) % queue->cap];
                }
            }
        }
        
        // Add the next element to the subsequence
        if (end < n) {
            current_sum += queue->arr[(queue->front + end) % queue->cap];
            end += 1;
        }
    }
    
    // Return the smallest subsequence that satisfies the condition
    *out_n = min_length;
}

int main() {
    Queue queue(1000);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);

    int x = 17;
    int result[1000];
    int out_n;

    find_subsequence(&queue, x, result, &out_n);

    std::cout << "[";
    for (int i = 0; i < out_n; i++) {
        std::cout << result[i];
        if (i < out_n-1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";  // Output: [2, 3, 4, 5, 6]

    return 0;
}


