struct Node {
    int data;
    Node* next;
};

int getNodeValue(Node* head, int fraction) {
    Node* slow = head;
    Node* fast = head;

    int steps = 0;

    while (fast != nullptr) {
        for (int i = 0; i < fraction && fast != nullptr; ++i)
            fast = fast->next;

        if (fast != nullptr)
            slow = slow->next;
    }

    return slow->data;
}
//here when first moves to end while slow reach n/k position

//write a function to find the fractional (n/k) node in a singly linked list

//length=6;
//k=2 hole node at the position [6/2]=3->value 30
//6/4 6/3 =2  value 20
10->20->30->40->50->60