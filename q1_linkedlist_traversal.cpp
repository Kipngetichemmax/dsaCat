
#include <iostream>
using namespace std;

// Singly Linked List Node
struct Node {
    int data;
    Node* next;
};

// Function to traverse the linked list
void traverse(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

int main() {

    // Creating nodes manually
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    // Assigning data
    head->data = 100;
    second->data = 200;
    third->data = 300;
    fourth->data = 400;
    fifth->data = 500;

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    // Traversal
    cout << "Linked List Traversal: ";
    traverse(head);

    return 0;
}





/*

====================================================
Q1: LINKED LIST TRAVERSAL
====================================================

Start → [100] → [200] → [300] → [400] → [500] → NULL

----------------------------------------------------
a) ALGORITHM
----------------------------------------------------
1. Set pointer current = start
2. While current != NULL:
      Print current.data
      Move current = current.next
3. Stop when current == NULL


----------------------------------------------------
b) PSEUDOCODE
----------------------------------------------------
TRAVERSE_LINKED_LIST(start)

    current ← start

    WHILE current ≠ NULL DO
        PRINT current.data
        current ← current.next
    END WHILE

END

----------------------------------------------------
c) EXPLANATION
----------------------------------------------------
Traversal uses a pointer that starts at the head node.
It visits each node, processes its data, and moves to the >
It stops when it reaches NULL (end of list).
====================================================


*/

