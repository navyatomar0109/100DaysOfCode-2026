struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* segregateEvenOdd(Node* head) {
    if (head == NULL)
        return head;

    Node *evenStart = NULL, *evenEnd = NULL;
    Node *oddStart = NULL, *oddEnd = NULL;
    Node *curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (evenStart == NULL) {
                evenStart = evenEnd = curr;
            } else {
                evenEnd->next = curr;
                evenEnd = curr;
            }
        } else {
            if (oddStart == NULL) {
                oddStart = oddEnd = curr;
            } else {
                oddEnd->next = curr;
                oddEnd = curr;
            }
        }
        curr = curr->next;
    }

    if (evenStart == NULL || oddStart == NULL)
        return head;

    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    return evenStart;
}