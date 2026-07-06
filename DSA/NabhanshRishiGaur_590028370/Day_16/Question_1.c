struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *nextPair = head->next->next;
    struct ListNode *newHead = head->next;

    newHead->next = head;
    head->next = swapPairs(nextPair);

    return newHead;
}
