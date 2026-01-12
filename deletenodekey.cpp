#include <iostream>
using namespace std;
//doubly linked list
// Node structure
struct Node {
    int key;
    Node* prev;
    Node* next;

    Node(int k) : key(k), prev(nullptr), next(nullptr) {}
};

// Function to delete a node with given key
void deleteNode(Node*& head, Node*& tail, int key) {
    Node* current = head;

    // Traverse the list to find the node
    while (current != nullptr && current->key != key) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Key not found." << endl;
        return;
    }

    // If node to delete is head
    if (current == head) {
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr; // If list becomes empty
    }
    // If node to delete is tail
    else if (current == tail) {
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
    }
    // Node is in the middle
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
}

// Utility: Print list forward
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* tail = third;

    // Linking nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Original list: ";
    printList(head);

    deleteNode(head, tail, 20);  // Delete node with key 20

    cout << "After deletion: ";
    printList(head);

    return 0;
}
