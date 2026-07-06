Node* segregateEvenOdd(Node* head) {

    if (!head || !head->next)
        return head;

    Node *evenHead = NULL, *evenTail = NULL;
    Node *oddHead = NULL, *oddTail = NULL;

    Node* curr = head;

    while (curr) {

        Node* next = curr->next;
        curr->next = NULL;

        if (curr->data % 2 == 0) {

            if (!evenHead)
                evenHead = evenTail = curr;
            else {
                evenTail->next = curr;
                evenTail = curr;
            }

        } else {

            if (!oddHead)
                oddHead = oddTail = curr;
            else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = next;
    }

    if (!evenHead)
        return oddHead;

    evenTail->next = oddHead;

    return evenHead;
}