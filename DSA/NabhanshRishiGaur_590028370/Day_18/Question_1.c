struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if (!head || !head->next || k == 0)
        return head;

    struct ListNode* temp = head;
    int length = 1;

    while (temp->next) {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;
    int steps = length - k;

    struct ListNode* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct ListNode* newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}
