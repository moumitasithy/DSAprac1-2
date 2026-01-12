struct Node {
    int data;
    Node* next;
};
int hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1; // Cycle detected
    }

    return 0; // No cycle
}