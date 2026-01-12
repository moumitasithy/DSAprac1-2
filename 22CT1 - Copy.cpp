struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) return;

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != nullptr)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;
}
//insert a new node after a given node