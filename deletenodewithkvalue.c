void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;

    // Find the node with the given key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If not found, return
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // If the node to be deleted is the head
    if (temp == *head_ref) {
        *head_ref = temp->next;
    }

    // Change next only if temp is NOT the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Change prev only if temp is NOT the first node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Free memory
    free(temp);
}
