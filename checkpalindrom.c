Node* reverseCopy(Node* head) {
    Node* reversed = NULL;

    while (head != NULL) {
        // Create a new node
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = head->data;

        // Insert at the beginning of the reversed list
        new_node->next = reversed;
        reversed = new_node;

        head = head->next;
    }

    return reversed;
}
//Compare two lists
int compare(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

 //Check palindrome
int isPalindrome(Node* head) {
    Node* reversed = reverseCopy(head);
    return compare(head, reversed);
}