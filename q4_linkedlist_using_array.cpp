
#include <iostream>
using namespace std;

class ArrayLinkedList {
private:
    static const int MAX = 100;

    struct Node {
        int data;
        int next;
    };

    Node arr[MAX];

    int head;
    int free;

public:
    ArrayLinkedList() {
        head = -1;

        // initialize free list
        for (int i = 0; i < MAX - 1; i++) {
            arr[i].next = i + 1;
        }
        arr[MAX - 1].next = -1;
        free = 0;
    }

    int getNode() {
        if (free == -1) {
            cout << "Overflow!\n";
            return -1;
        }

        int index = free;
        free = arr[free].next;
        return index;
    }

    void freeNode(int index) {
        arr[index].next = free;
        free = index;
    }

    void insertFront(int value) {
        int newNode = getNode();
        if (newNode == -1) return;

        arr[newNode].data = value;
        arr[newNode].next = head;
        head = newNode;
    }

    void deleteFront() {
        if (head == -1) {
            cout << "List empty\n";
            return;
        }

        int temp = head;
        head = arr[head].next;
        freeNode(temp);
    }

    void display() {
        int temp = head;

        while (temp != -1) {
            cout << arr[temp].data << " -> ";
            temp = arr[temp].next;
        }

        cout << "NULL\n";
    }
};

//MAIN
int main() {
    ArrayLinkedList list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);

    cout << "List: ";
    list.display();

    list.deleteFront();

    cout << "After deletion: ";
    list.display();

    return 0;
}
