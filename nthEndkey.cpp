#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to get nth node from end
int getNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;

    // Move fast n steps ahead
    for (int i = 0; i < n; ++i) {
        if (!fast) return -1;  // n is larger than list length
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow ? slow->data : -1;
}


int main() {
    Node* head = nullptr;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    int n = 2;
    int value = getNthFromEnd(head, n);

    if (value != -1)
        cout << n << "th node from end has value: " << value << endl;
    else
        cout << "Position is greater than the list length." << endl;

    return 0;
}
