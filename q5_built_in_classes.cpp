
#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main() {

    // =========================
    // a) STACK (LIFO)
    // =========================
    cout << "STACK DEMO\n";

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    st.pop(); // removes 30

    cout << "After pop, top: " << st.top() << endl;

    cout << "Stack elements: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n\n";


    // =========================
    // b) QUEUE (FIFO)
    // =========================
    cout << "QUEUE DEMO\n";

    queue<int> q;

    q.push(100);
    q.push(200);
    q.push(300);

    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.back() << endl;

    q.pop(); // removes 100

    cout << "After pop, front: " << q.front() << endl;

    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n\n";


    // =========================
    // c) LINKED LIST (std::list)
    // =========================
    cout << "LINKED LIST DEMO\n";

    list<int> ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_front(0);

    cout << "List elements: ";
    for (int x : ll) {
        cout << x << " ";
    }
    cout << endl;

    ll.pop_front();
    ll.pop_back();

    cout << "After pop operations: ";
    for (int x : ll) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
