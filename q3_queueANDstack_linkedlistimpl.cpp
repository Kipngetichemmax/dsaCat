
#include <iostream>
using namespace std;


//STACK 

#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "Stack: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};









//QUEUES




// =====================================================
// 1. LINEAR QUEUE (Linked List)
// =====================================================
class LinearQueue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node *front, *rear;

public:
    LinearQueue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Linear Queue Underflow!\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Linear Queue empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Linear Queue: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


// =====================================================
// 2. CIRCULAR QUEUE (Linked List)
// =====================================================
class CircularQueue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* rear;

public:
    CircularQueue() {
        rear = nullptr;
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;
            return;
        }

        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow!\n";
            return;
        }

        Node* front = rear->next;

        if (front == rear) {
            delete rear;
            rear = nullptr;
        } else {
            rear->next = front->next;
            delete front;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue empty!\n";
            return;
        }

        cout << "Circular Queue: ";

        Node* temp = rear->next;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);

        cout << endl;
    }
};


// =====================================================
// 3. PRIORITY QUEUE (Linked List)
// Lower value = higher priority
// =====================================================
class PriorityQueue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty() || value < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr && temp->next->data <= value) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow!\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue empty!\n";
            return;
        }

        Node* temp = head;
        cout << "Priority Queue: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


// =====================================================
// MAIN (TEST ALL)
// =====================================================
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
