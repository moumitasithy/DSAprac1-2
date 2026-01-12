void reverseList(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;     // Store next node
        current->next = prev;     // Reverse current node's pointer
        prev = current;           // Move prev to current
        current = next;           // Move to next node
    }

    *head_ref = prev;             // Update head to new first node
}
//o{1} space