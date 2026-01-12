struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

Node* getIntersection(Node* head1, Node* head2) {
    Node* dummy = new Node(0);  // dummy head for new list
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            tail->next = new Node(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }

    return dummy->next;
}
