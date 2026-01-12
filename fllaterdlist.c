/ Function to flatten the list
Node* flattenList(Node* head) {
    if (!head) return NULL;

    Node* tail = head;

    // Find the current tail
    while (tail->next)
        tail = tail->next;

    Node* curr = head;

 while (curr) {
        if (curr->child) {
            // Attach child list to tail
            tail->next = curr->child;

            // Move tail to new end
            Node* temp = curr->child;
            while (temp->next)
                temp = temp->next;
            tail = temp;
        }
        curr = curr->next;
    }

    return head;
}
