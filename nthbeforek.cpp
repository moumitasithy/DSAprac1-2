struct Node {
    int key;
    Node* next;
};

int findNthBeforeK(Node* head, int k, int n) {
    Node* target = head;
    Node* nthBefore = nullptr;

    int count = 0;
    while (target != nullptr) {
        if (target->key == k) break;

        if (count >= n) {
            if (nthBefore == nullptr)
                nthBefore = head;
            else
                nthBefore = nthBefore->next;
        }

        target = target->next;
        count++;
    }

    if (target == nullptr || nthBefore == nullptr)
        return -1;  // Not found or less than n nodes before

    return nthBefore->key;
}
//Given a singly linked list and two integers k and n, return the key of the node that is n positions before the node that has key k.
//Assume all keys are unique.
/*
List: 5 → 10 → 20 → 30 → 40 → 50 → 60
Input: k = 40, n = 2
Output: 20
(20 is 2 nodes before the node with key 40*/
