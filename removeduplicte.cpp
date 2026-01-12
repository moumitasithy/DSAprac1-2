struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    Node* curr = head;

    while (curr != nullptr && curr->next != nullptr) {
        if (curr->data == curr->next->data) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}
//sorted singly linked  list
//unsorted jonno
void removeDuplicatesNoExtraSpace(Node* head) {
    Node* curr = head;

    while (curr) {
        Node* runner = curr;
        while (runner->next) {
            if (runner->next->data == curr->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}
