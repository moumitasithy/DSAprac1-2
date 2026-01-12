void deleteNthNodes(int N) {
    if (N <= 0) return;

    struct listNode* current = head;
    int count = 1;

    while (current != NULL) {
        struct listNode* nextNode = current->next;
        if (count % N == 0) {
            // Delete current
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                head = current->next;  // current is head

            if (current->next != NULL)
                current->next->prev = current->prev;
            else
                tail = current->prev;  // current is tail

            free(current);
        }
        count++;
        current = nextNode;
    }
}
//Implement void delete(int N) that deletes every N-th node (i.e., nodes at positions N, 2N, 3N, ...) with 1-based indexing.

//ekhane next nide lagbe karon ami current free kore dicchi