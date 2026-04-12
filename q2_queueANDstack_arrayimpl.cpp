
#include <iostream>
using namespace std;



//STACK

class Stack {
private:
    static const int MAX = 100;
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};










//QUEUES-------------------------------


#define MAX 100

// LINEAR QUEUE
class LinearQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    LinearQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Linear Queue Overflow!\n";
            return;
        }

        if (front == -1) front = 0;

        arr[++rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Linear Queue Underflow!\n";
            return;
        }
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Linear Queue empty!\n";
            return;
        }

        cout << "Linear Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


// CIRCULAR QUEUE
class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Circular Queue Overflow!\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow!\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue empty!\n";
            return;
        }

        cout << "Circular Queue: ";

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};


// PRIORITY QUEUE (Ascending priority: smaller = higher priority)
class PriorityQueue {
private:
    int arr[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Priority Queue Overflow!\n";
            return;
        }

        int i = size - 1;

        // shift elements to maintain sorted order
        while (i >= 0 && arr[i] > value) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow!\n";
            return;
        }

        // remove highest priority (smallest element → front)
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue empty!\n";
            return;
        }

        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


// MAIN
int main() {


    cout << "===== STACK  =====\n";
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top: " << s.peek() << endl;

    s.pop();
    s.display();




    cout << "===== LINEAR QUEUE =====\n";
    LinearQueue lq;
    lq.enqueue(10);
    lq.enqueue(20);
    lq.enqueue(30);
    lq.display();
    lq.dequeue();
    lq.display();

    cout << "\n===== CIRCULAR QUEUE =====\n";
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();
    cq.dequeue();
    cq.display();

    cout << "\n===== PRIORITY QUEUE =====\n";
    PriorityQueue pq;
    pq.enqueue(50);
    pq.enqueue(10);
    pq.enqueue(30);
    pq.enqueue(20);
    pq.display();
    pq.dequeue();
    pq.display();

    return 0;
}
