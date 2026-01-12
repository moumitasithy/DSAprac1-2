struct Node {
    int data;
    Node* next;
};

void deleteNextK(Node* head, int m, int k) {
    Node* curr = head;

    // Step 1: Find node with value m
    while (curr != nullptr && curr->data != m) {
        curr = curr->next;
    }

    if (curr == nullptr) return; // m not found

    // Step 2: Delete next k nodes
    Node* temp = curr->next;
    while (temp != nullptr && k--) {
        Node* del = temp;
        temp = temp->next;
        delete del;
    }

    // Step 3: Reconnect the remaining list
    curr->next = temp;
}
