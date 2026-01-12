void deleteNode(Node*& head, Node* delNode) {
    if (head == nullptr || delNode == nullptr) return;

    // If the node to be deleted is head
    if (head == delNode)
        head = delNode->next;

    if (delNode->next != nullptr)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != nullptr)
        delNode->prev->next = delNode->next;

    delete delNode;
}
//delete given node